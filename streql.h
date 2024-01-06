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
    size_t* pa = (size_t*)a;
    size_t* pb = (size_t*)b;
    while (1) {
        if (!(*pa && !(*pa ^ *pb))) break;
        ++pa; ++pb;
    }
    return !strncmp((const char*)pa, (const char*)pb, sizeof(size_t));
}

#endif
