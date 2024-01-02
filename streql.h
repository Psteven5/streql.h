#ifndef STREQL
#define STREQL

#include <stdbool.h>
#include <stdint.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    const uint32_t* _a = (const uint32_t*)a;
    const uint32_t* _b = (const uint32_t*)b;
    uint32_t al, bl;
    do {
        al = *_a++;
        bl = *_b++;
    } while (al && al == bl);
    return !bl;
}

/*
-- x64 inline assembly variant of streql() --
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql_x64(const char* a, const char* b) {
    bool ret;
    asm(
        ".STREQL_LOOP:"
        "movl (%1), %%eax;"
        "movl (%2), %%ebx;"
        "addq $4, %1;"
        "addq $4, %2;"
        "testl %%eax, %%eax;"
        "jz .STREQL_END;"
        "cmpl %%eax, %%ebx;"
        "je .STREQL_LOOP;"
        ".STREQL_END:"
        "testl %%ebx, %%ebx;"
        "setzb %0;"
        : "=r" (ret)
        : "r" (a), "r" (b)
        : "rax", "%rbx", "%rcx", "%rdx"
    );
    return ret;
}

#endif
