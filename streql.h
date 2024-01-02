#ifndef STREQL
#define STREQL

#include <stdbool.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    const unsigned int* _a = (const unsigned int*)a;
    const unsigned int* _b = (const unsigned int*)b;
    unsigned int al, bl;
    do {
        al = *_a++;
        bl = *_b++;
    } while (al - bl);
    return al - (bl << 1);
}

/*
-- x64 inline assembly variant of streql() --
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    bool ret;
    asm(
        "leaq (%1), %%rcx;"
        "leaq (%2), %%rdx;"
        ".STREQL_LOOP:"
        "movl (%%rcx), %%eax;"
        "movl (%%rdx), %%ebx;"
        "addq $4, %%rcx;"
        "addq $4, %%rdx;"
        "testl %%eax, %%eax;"
        "jz .STREQL_END;"
        "xorl %%eax, %%ebx;"
        "jz .STREQL_LOOP;"
        ".STREQL_END:"
        "xorl %%eax, %%ebx;"
        "setz %0;"
        : "=r" (ret)
        : "r" (a), "r" (b)
        : "rax", "%rbx", "%rcx", "%rdx"
    );
    return ret;
}

#endif
