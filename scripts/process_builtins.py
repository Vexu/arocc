#!/usr/bin/env python3
"""
process_builtins.py

Tested with python 3.10

Intended usage: python3 scripts/process_builtins.py path/to/Builtins*.def | zig fmt --stdin > src/builtins/BuiltinFunction.zig
"""

from __future__ import annotations
from dataclasses import dataclass
import enum
import fileinput
import itertools
import operator
import os
import re
import sys
import typing


NAME = r'(?P<name>\w*)'
PARAMS = r'"(?P<params>[\w.*&]*)"'
ATTRS = r'"(?P<attrs>[\w:<>,\d]*)"'
HEADER = r'"(?P<header>[\w./-]+)"'
LANG = r'(?P<lang>\w*)'
COMMA = r'\W*,\W*'

# BUILTIN(__builtin_atan2 , "ddd"  , "Fne")
BUILTIN_REGEX = re.compile(fr"""
BUILTIN\(\W*
    {NAME} {COMMA} {PARAMS} {COMMA} {ATTRS}
\W*\)
""", re.ASCII | re.VERBOSE)

# LANGBUILTIN(_alloca,          "v*z", "n", ALL_MS_LANGUAGES)
LANGBUILTIN_REGEX = re.compile(fr"""
LANGBUILTIN\(\W*
    {NAME} {COMMA} {PARAMS} {COMMA} {ATTRS} {COMMA} {LANG}
\W*\)
""", re.ASCII | re.VERBOSE)

# LIBBUILTIN(exit, "vi",            "fr",    "stdlib.h", ALL_LANGUAGES)
LIBBUILTIN_REGEX = re.compile(fr"""
LIBBUILTIN\(\W*
    {NAME} {COMMA} {PARAMS} {COMMA} {ATTRS} {COMMA} {HEADER} {COMMA} {LANG}
\W*\)
""", re.ASCII | re.VERBOSE)

TypePrefixMap = {
    'L': 'long (e.g. Li for \'long int\', Ld for \'long double\')',
    'LL': 'long long (e.g. LLi for \'long long int\', LLd for __float128)',
    'LLL': '__int128_t (e.g. LLLi)',
    'Z': 'int32_t (require a native 32-bit integer type on the target)',
    'W': 'int64_t (require a native 64-bit integer type on the target)',
    'N': '\'int\' size if target is LP64, \'L\' otherwise.',
    'O': 'long for OpenCL targets, long long otherwise.',
    'S': 'signed',
    'U': 'unsigned',
    'I': 'Required to constant fold to an integer constant expression.',
}

TypeSpecMap = {
    'v': 'void',
    'b': 'boolean',
    'c': 'char',
    's': 'short',
    'i': 'int',
    'h': 'half (__fp16, OpenCL)',
    'x': 'half (_Float16)',
    'y': 'half (__bf16)',
    'f': 'float',
    'd': 'double',
    'z': 'size_t',
    'w': 'wchar_t',
    'F': 'constant CFString',
    'G': 'id',
    'H': 'SEL',
    'M': 'struct objc_super',
    'a': '__builtin_va_list',
    'A': '"reference" to __builtin_va_list',
    'V': 'Vector, followed by the number of elements and the base type.',
    'q': 'Scalable vector, followed by the number of elements and the base type.',
    'E': 'ext_vector, followed by the number of elements and the base type.',
    'X': '_Complex, followed by the base type.',
    'Y': 'ptrdiff_t',
    'P': 'FILE',
    'J': 'jmp_buf',
    'SJ': 'sigjmp_buf',
    'K': 'ucontext_t',
    'p': 'pid_t',
    '.': '"...".  This may only occur at the end of the function list.',
}

TypeSuffixMap = {
    '*' : 'pointer (optionally followed by an address space number,' \
            'if no address space is specified than any address space will be accepted)',
    '&' : 'reference (optionally followed by an address space number)',
    'C' : 'const',
    'D' : 'volatile',
    'R' : 'restrict',
}

def type_spec_regex(keys) -> str:
    one_letter = ''.join(key for key in keys if len(key) == 1)
    two_letter = [key for key in keys if len(key) == 2]
    if two_letter != ['SJ']:
        raise RuntimeError(f'Unexpected two-letter keys {two_letter}')
    return fr'(?P<spec>SJ|[{one_letter}])'


TYPE_REGEX = re.compile(fr"""
    (?P<prefix>(LL|LLL|[LZWNOSUI](?!J))*)            # Ignore trailing J because `SJ` is the sigjmp_buf spec
    {type_spec_regex(TypeSpecMap)}                   # (?P<spec>SJ|[vbcsihxyfdzwFGHMaAVqEXYPJKp.])
    (?P<suffix>[{''.join(TypeSuffixMap.keys())}]*)
""", re.ASCII | re.VERBOSE)

class Language(enum.Enum):
    """
        Language for which a builtin is available
    """
    ALL_LANGUAGES = enum.auto()
    CXX_LANG = enum.auto()
    ALL_MS_LANGUAGES = enum.auto()
    ALL_GNU_LANGUAGES = enum.auto()
    GNU_LANG = enum.auto()
    COR_LANG = enum.auto()
    OCL_PIPE = enum.auto()
    OCL_DSE = enum.auto()
    OCL_GAS = enum.auto()
    ALL_OCL_LANGUAGES = enum.auto()
    CUDA_LANG = enum.auto()
    HLSL_LANG = enum.auto()
    OBJC_LANG = enum.auto()

    @property
    def allowed(self) -> bool:
        """
            A language we know how to handle
        """
        return self in {
            Language.ALL_LANGUAGES,
            Language.ALL_MS_LANGUAGES,
            Language.ALL_GNU_LANGUAGES,
            Language.GNU_LANG,
        }

class Header(enum.Enum):
    """
        Library header which contains the declaration for a builtin
    """
    stdio = 'stdio.h'
    stdlib = 'stdlib.h'
    setjmpex = 'setjmpex.h'
    stdarg = 'stdarg.h'
    string = 'string.h'
    ctype = 'ctype.h'
    wchar = 'wchar.h'
    setjmp = 'setjmp.h'
    malloc = 'malloc.h'
    strings = 'strings.h'
    unistd = 'unistd.h'
    pthread = 'pthread.h'
    objc_message = 'objc/message.h'
    objc_runtime = 'objc/runtime.h'
    objc_objc_auto = 'objc/objc-auto.h'
    objc_objc_exception = 'objc/objc-exception.h'
    objc_objc_sync = 'objc/objc-sync.h'
    Foundation_NSObjCRuntime = 'Foundation/NSObjCRuntime.h'
    math = 'math.h'
    complex = 'complex.h'
    Blocks = 'Blocks.h'
    memory = 'memory'
    utility = 'utility'

    @classmethod
    def parse(cls, val: typing.Optional[str]) -> typing.Optional[Header]:
        if val is None:
            return None
        return cls(val)

class Target(enum.Enum):
    aarch64 = 'aarch64'
    aarch64_neon_sve_bridge = 'aarch64neonsvebridge'
    aarch64_neon_sve_bridge_cg = 'aarch64neonsvebridge_cg'
    amdgpu = 'amdgpu'
    arm = 'arm'
    bpf = 'bpf'
    hexagon = 'hexagon'
    hexagon_dep = 'hexagondep'
    hexagon_map_custom_dep = 'hexagonmapcustomdep'
    loong_arch = 'loongarch'
    mips = 'mips'
    neon = 'neon'
    nvptx = 'nvptx'
    ppc = 'ppc'
    riscv = 'riscv'
    riscv_vector = 'riscvvector'
    sve = 'sve'
    systemz = 'systemz'
    ve = 've'
    vevl_gen = 'vevl.gen'
    webassembly = 'webassembly'
    x86 = 'x86'
    x86_64 = 'x86_64'
    xcore = 'xcore'

    @classmethod
    def parse(cls, val: typing.Optional[str]) -> typing.Optional[Target]:
        if val is None:
            return None
        return cls(val)


@dataclass
class TypeDescription:
    prefix: str
    spec: str
    suffix: str

@dataclass
class Builtin:
    """
        Builtin function description
    """
    name: str
    param_str: str
    param_count: int
    attrs: str
    lang: Language
    header: typing.Optional[Header]
    target: typing.Optional[Target]

    def equivalent_prototypes(self, other: Builtin) -> bool:
        """
            Determines if two same-name builtins have the same prototype
            Used to coalesce target-specific builtins that work on multiple targets
        """
        if self.name != other.name:
            raise RuntimeError(
                f'Attempted to compare builtins with different names: {self.name} and {other.name}')
        return self.param_str == other.param_str and self.attrs == other.attrs

def _parse_params(description: str) -> typing.List[TypeDescription]:
    if not description:
        return []
    output = []
    for entry in TYPE_REGEX.finditer(description):
        group = entry.groupdict()
        output.append(TypeDescription(**group))
    return output

def _parse_builtin(line: str, regex: typing.Pattern, target: typing.Optional[Target]) -> typing.Optional[Builtin]:
    result = regex.match(line)
    if result is None:
        return None

    group = result.groupdict()
    params = group['params']
    parsed_params = _parse_params(params)
    if not parsed_params:
        # For some reason pthread_create is missing return type / param info, so skip it
        # Every other function should at least have a return type
        if group['name'] == 'pthread_create':
            return None
        raise RuntimeError(f'Missing return type for {group["name"]}')

    return Builtin(
        name=group['name'],
        param_str=params,
        param_count=len(parsed_params) - 1, # first parsed param is return type
        attrs=group['attrs'],
        header=Header.parse(group.get('header')),
        lang=Language[group.get('lang', 'ALL_LANGUAGES')],
        target=target,
    )

def _parse_line(line: str, target: typing.Optional[Target]) -> typing.Optional[Builtin]:
    if line.startswith('BUILTIN'):
        regex = BUILTIN_REGEX
    elif line.startswith('LANGBUILTIN'):
        regex = LANGBUILTIN_REGEX
    elif line.startswith('LIBBUILTIN'):
        regex = LIBBUILTIN_REGEX
    else:
        return None

    return _parse_builtin(line, regex, target)

def escape_identifier(name: str) -> str:
    """
        Escape a Zig identifier
    """
    if re.match(r'^[A-Za-z0-9_]+$', name):
        return name
    return f'@"{name}"'

def split_prefixes(prefix: str) -> typing.List[str]:
    """
        Split the prefixes of a TypeDescription
    """
    out = []
    while prefix:
        if prefix.startswith('LLL'):
            out.append('LLL')
            prefix = prefix[3:]
        elif prefix.startswith('LL'):
            out.append('LL')
            prefix = prefix[2:]
        else:
            out.append(prefix[0])
            prefix = prefix[1:]
    return out

def render_type_description(ty: TypeDescription) -> None:
    """
        Render a TypeDescription
    """
    print('.{')
    print('.prefix = &.{')
    for prefix in split_prefixes(ty.prefix):
        print(f'.{escape_identifier(prefix)},')
    print('},')
    print(f'.spec = .{escape_identifier(ty.spec)},')
    print('.suffix = &.{')
    for char in ty.suffix:
        print(f'.{escape_identifier(char)},')
    print('},')
    print('}')

def render_attributes(attrs: str) -> None:
    """
        Render a BuiltinAttributes struct
    """
    if not attrs:
        return
    print('const attributes = Attributes{')
    if 'r' in attrs:
        print('.noreturn = true,')
    if 'U' in attrs:
        print('.pure = true,')
    if 'c' in attrs:
        print('.@"const" = true,')
    if 't' in attrs:
        print('.custom_typecheck = true,')
    if 'T' in attrs:
        print('.allow_type_mismatch = true,')
    if 'F' in attrs:
        print('.lib_function_with_builtin_prefix = true,')
    if 'f' in attrs:
        print('.lib_function_without_prefix = true,')
    if 'j' in attrs:
        print('.returns_twice = true,')
    if 'u' in attrs:
        print('.eval_args = false,')
    if 'e' in attrs:
        print('.const_without_errno_and_fp_exceptions = true,')
    if 'g' in attrs:
        print('.const_without_fp_exceptions = true,')
    if 'E' in attrs:
        print('.const_evaluable = true,')
    if match := re.search(r'([sSpP]):(\d+):', attrs):
        groups = match.groups()
        format_kinds = {
            'p': 'printf',
            'P': 'vprintf',
            's': 'scanf',
            'S': 'vscanf',
        }
        print(f'.format_kind = .{format_kinds[groups[0]]},')
        print(f'.format_string_position = {groups[1]},')
    print('};')

def render_targets(targets: typing.Sequence[Target]) -> None:
    if not targets:
        return
    print("const target_set = TargetSet.init(.{")
    for target in targets:
        print(f'.{target.name} = true,')
    print("});")

def render_builtin(builtin: Builtin, targets: typing.Sequence[Target]) -> None:
    """
        Render a description of a C builtin
    """
    if not builtin.lang.allowed:
        return
    if '&' in builtin.param_str:
        return

    print(f'const {builtin.name} = struct {{')
    print(f'const param_str = "{builtin.param_str}";')

    if builtin.lang != Language.ALL_LANGUAGES:
        print(f'const language = .{builtin.lang.name.lower()};')
    if builtin.header:
        print(f'const header = .{builtin.header.name.lower()};')
    render_targets(targets)

    render_attributes(builtin.attrs)
    print('};\n')

def render_prelude(script: str) -> None:
    """
        Generate the prelude
    """
    print(f"//! Autogenerated by {script}, do not edit")
    print("""
    const std = @import("std");
    const Properties = @import("Properties.zig");
    const TypeDescription = @import("TypeDescription.zig");
    const Attributes = Properties.Attributes;
    const TargetSet = Properties.TargetSet;

    pub const Tag = blk: {
        @setEvalBranchQuota(10000);
        break :blk std.meta.DeclEnum(functions);
    };

    tag: Tag,
    param_str: []const u8,
    properties: Properties,

    pub fn fromTag(builtin: Tag) @This() {
        @setEvalBranchQuota(10000);
        switch (builtin) {
            inline else => |tag| {
                const desc = @field(functions, @tagName(tag));
                return .{
                    .tag = tag,
                    .param_str = desc.param_str,
                    .properties = .{
                        .language = if (@hasDecl(desc, "language")) @field(desc, "language") else .all_languages,
                        .header = if (@hasDecl(desc, "header")) @field(desc, "header") else .none,
                        .attributes = if (@hasDecl(desc, "attributes")) @field(desc, "attributes") else Attributes{},
                        .target_set = if (@hasDecl(desc, "target_set")) @field(desc, "target_set") else TargetSet.init(.{ .basic = true }),
                    },
                };
            },
        }
    }

    pub fn isVarArgs(self: @This()) bool {
        return self.param_str[self.param_str.len - 1] == '.';
    }
    """)

def get_target(path: str) -> typing.Optional[Target]:
    """
        Get the target for a given definitions file
    """
    name = os.path.basename(path).lower().removeprefix('builtins').removesuffix('.def') or None
    return Target.parse(name)

def main() -> int:
    """
        main
    """
    if len(sys.argv) < 2:
        print(f'Usage: {sys.argv[0]} path/to/Builtins.def', file=sys.stderr)
        return 1

    all_builtins = []
    for line in fileinput.input(encoding='utf-8'):
        target = get_target(fileinput.filename())
        builtin = _parse_line(line, target)
        if builtin is None:
            continue
        all_builtins.append(builtin)

    all_builtins.sort(key=operator.attrgetter('name'))

    render_prelude(os.path.basename(sys.argv[0]))

    max_param_count = 0
    print('const functions = struct {')
    for _name, grouper in itertools.groupby(all_builtins, key=operator.attrgetter('name')):
        group = list(grouper)
        first = group[0]

        targets = [builtin.target for builtin in group]
        if targets == [None]:
            targets = []

        for builtin in group[1:]:
            if not first.equivalent_prototypes(builtin):
                first.param_str = "!"
                break

        max_param_count = max(max_param_count, first.param_count)
        render_builtin(first, typing.cast(typing.List[Target], targets))

    print('};')
    print(f'pub const MaxParamCount = {max_param_count};')

    return 0

if __name__ == '__main__':
    sys.exit(main())
