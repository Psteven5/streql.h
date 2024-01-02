#ifndef STREQL
#define STREQL

#include <stdbool.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    bool result;
    asm(
        ".LOOP:"
        "movb (%1), %%al;"
        "movb (%2), %%bl;"
        "movb +1(%1), %%ah;"
        "movb +1(%2), %%bh;"
        "incq %1;"
        "incq %2;"
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
    return result;
}

#endif
