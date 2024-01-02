#ifndef STREQL
#define STREQL

#include <stdbool.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    unsigned short as, bs;
    do {
        as = *(a += 2);
        bs = *(b += 2);
    } while (as == bs && as - (as >> 8));
    return as == bs;
}

/*
-- x64 inline assembly variant of streql() --
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql_x64(const char* a, const char* b) {
    bool ret;
    asm(
        "leaq (%1), %%rcx;"
        "leaq (%2), %%rdx;"
        ".STREQL_LOOP:"
        "mov (%%rcx), %%ax;"
        "mov (%%rdx), %%bx;"
        "addq $2, %%rcx;"
        "addq $2, %%rdx;"
        "testb %%al, %%al;"
        "andb %%ah, %%ah;"
        "jz .STREQL_END;"
        "xor %%ax, %%bx;"
        "jz .STREQL_LOOP;"
        ".STREQL_END:"
        "xor %%ax, %%bx;"
        "setz %0;"
        : "=r" (ret)
        : "r" (a), "r" (b)
        : "rax", "%rbx", "%rcx", "%rdx"
    );
    return ret;
}

#endif
