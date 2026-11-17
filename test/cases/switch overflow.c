void unsigned_char(unsigned char input) {
    switch (input) {
        case 0: break;
        case 255: break;
        case 256: break;
        case 258: break;
        case -1: break;
        case 2: break;
    }
}

void signed_char(signed char input) {
    switch (input) {
        case -128: break;
        case 127: break;
        case 128: break;
        case 255: break;
        case -129: break;
    }
}

void ranges(unsigned char input) {
    switch (input) {
        case 0 ... 3: break;
        case 254 ... 258: break;
        case 260 ... 262: break;
        case -4 ... -2: break;
    }
}

void explicit_promotion(unsigned char input) {
    switch ((int)input) {
        case 258: break;
    }
}

void init_statement(unsigned char input) {
    switch (unsigned char x = input; x) {
        case 258: break;
    }
}

void nested(unsigned char input) {
    switch (input) {
        case 0:
            switch ((int)input) {
                case 258: break;
            }
            break;
        case 258: break;
        case 2: break;
    }
}

void wide_case(int input) {
    switch (input) {
        case 4294967296LL: break;
        case -1LL: break;
    }
}

void unsigned_condition(unsigned int input) {
    switch (input) {
        case -1: break;
        case 4294967296LL: break;
    }
}

void signed_condition(int input) {
    switch (input) {
        case 4294967295U: break;
        case 1: break;
    }
}

void bit_int(unsigned _BitInt(3) input) {
    switch (input) {
        case 7: break;
        case 8: break;
    }
}

void boolean(_Bool input) {
    switch (input) {
        case 1: break;
        case 2: break;
    }
}

void large_case(int input) {
    switch (input) {
        case (unsigned __int128)1 << 100: break;
    }
}

enum byte : unsigned char { zero, max = 255 };
void fixed_enum(enum byte input) {
    switch (input) {
        case 255: break;
        case 258: break;
    }
}

#pragma GCC diagnostic ignored "-Wswitch"
void suppressed(unsigned char input) {
    switch (input) {
        case 258: break;
    }
    switch ((int)input) {
        case 4294967296LL: break;
    }
}

#pragma GCC diagnostic error "-Wswitch"
void promoted_to_error(unsigned char input) {
    switch (input) {
        case 258: break;
    }
}

/** manifest:
syntax
args = -std=c2y -Wswitch -target x86_64-linux-musl

switch overflow.c:5:14: warning: overflow converting case value to switch condition type (256 to 0) [-Wswitch]
switch overflow.c:6:14: warning: overflow converting case value to switch condition type (258 to 2) [-Wswitch]
switch overflow.c:7:14: warning: overflow converting case value to switch condition type (-1 to 255) [-Wswitch]
switch overflow.c:16:14: warning: overflow converting case value to switch condition type (128 to -128) [-Wswitch]
switch overflow.c:17:14: warning: overflow converting case value to switch condition type (255 to -1) [-Wswitch]
switch overflow.c:18:14: warning: overflow converting case value to switch condition type (-129 to 127) [-Wswitch]
switch overflow.c:25:22: warning: overflow converting case value to switch condition type (258 to 2) [-Wswitch]
switch overflow.c:26:14: warning: overflow converting case value to switch condition type (260 to 4) [-Wswitch]
switch overflow.c:26:22: warning: overflow converting case value to switch condition type (262 to 6) [-Wswitch]
switch overflow.c:27:14: warning: overflow converting case value to switch condition type (-4 to 252) [-Wswitch]
switch overflow.c:27:21: warning: overflow converting case value to switch condition type (-2 to 254) [-Wswitch]
switch overflow.c:39:14: warning: overflow converting case value to switch condition type (258 to 2) [-Wswitch]
switch overflow.c:50:14: warning: overflow converting case value to switch condition type (258 to 2) [-Wswitch]
switch overflow.c:57:14: warning: overflow converting case value to switch condition type (4294967296 to 0) [-Wswitch]
switch overflow.c:65:14: warning: overflow converting case value to switch condition type (4294967296 to 0) [-Wswitch]
switch overflow.c:79:14: warning: overflow converting case value to switch condition type (8 to 0) [-Wswitch]
switch overflow.c:86:14: warning: overflow converting case value to switch condition type (2 to 0) [-Wswitch]
switch overflow.c:92:14: warning: overflow converting case value to switch condition type (1267650600228229401496703205376 to 0) [-Wswitch]
switch overflow.c:100:14: warning: overflow converting case value to switch condition type (258 to 2) [-Wswitch]
switch overflow.c:117:14: error: overflow converting case value to switch condition type (258 to 2) [-Werror,-Wswitch]
*/
