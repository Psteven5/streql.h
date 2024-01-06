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
    size_t ai, bi;
    do {
        memcpy(&ai, a, sizeof(size_t));
        if (!ai) break;
        memcpy(&bi, b, sizeof(size_t));
        if (ai ^ bi) break;
        a += sizeof(size_t);
        b += sizeof(size_t);
    } while (1);
    return !strncmp(a, b, sizeof(size_t));
}

#endif
