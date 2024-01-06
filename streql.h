#ifndef STREQL
#define STREQL

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    const size_t* pa = (const size_t*)a;
    const size_t* pb = (const size_t*)b;
    size_t ai, bi;
    do {
        memcpy(&ai, pa, sizeof(size_t));
        if (!ai) break;
        memcpy(&bi, pb, sizeof(size_t));
        if (ai ^ bi) break;
        ++pa;
        ++pb;
    } while (1);
    return !strncmp((const char*)pa, (const char*)pb, sizeof(size_t));
}

#endif
