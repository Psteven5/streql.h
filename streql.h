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
    size_t i = 0;
    for (;;) {
        memcpy(&ai, a + i, sizeof(size_t));
        if (!ai) break;
        memcpy(&bi, b + i, sizeof(size_t));
        if (ai ^ bi) break;
        i += sizeof(size_t);
    }
    return !strncmp(a + i, b + i, sizeof(size_t));
}

#endif
