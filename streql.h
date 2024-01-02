#ifndef STREQL
#define STREQL

#include <stdbool.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    bool ret;
    asm(
        "leaq (%1), %%rcx;"
        "leaq (%2), %%rdx;"
        ".LOOP:"
        "mov (%%rcx), %%ax;"
        "mov (%%rdx), %%bx;"
        "addq $2, %%rcx;"
        "addq $2, %%rdx;"
        "testb %%al, %%ah;"
        "jz .END;"
        "xor %%ax, %%bx;"
        "jz .LOOP;"
        ".END:"
        "xor %%ax, %%bx;"
        "setz %0;"
        : "=r" (ret)
        : "r" (a), "r" (b)
        : "rax", "%rbx", "%rcx", "%rdx"
    );
    return ret;
}

#endif
