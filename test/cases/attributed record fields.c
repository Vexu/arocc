struct S1 {};

struct S2 {
    __attribute__((packed)) int x;
};

struct S3 {
    int __attribute__((packed)) x;
};

struct S4 {
    int x __attribute__((packed));
};

struct S5 {
    __attribute__((packed)) int x, y;
};

struct S6 {
    int __attribute__((packed)) x, y;
};

struct S7 {
     int x __attribute__((packed)), y;
};

struct S8 {
     int x, y __attribute__((packed));
};

struct S9 {
    int __attribute__((packed)) x __attribute__((aligned));
    float f;
    __attribute__((packed)) long __attribute__((aligned(16))) l __attribute__((warn_if_not_aligned(16)));
};

union U1 {
    long x;
    __attribute__((aligned(32))) int y;
    unsigned __attribute__((packed)) z;
};

union U2 {
    int x __attribute__((packed)), y, __attribute__((packed)) z, w __attribute__((aligned));
};

/** manifest:
syntax
args = --target=x86_64-windows-msvc
*/
