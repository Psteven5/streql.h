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
        ".LOOP:"
        "mov (%1), %%ax;"
        "mov (%2), %%bx;"
        "addq $2, %1;"
        "addq $2, %2;"
        "testb %%al, %%al;"
        "andb %%ah, %%ah;"
        "jz .END;"
        "xor %%ax, %%bx;"
        "jz .LOOP;"
        ".END:"
        "xor %%ax, %%bx;"
        "setz %0;"
        : "=r" (ret)
        : "r" (a), "r" (b)
        : "%ax", "%bx"
    );
    return ret;
}

#endif
