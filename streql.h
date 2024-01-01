#ifndef STREQL
#define STREQL

#include <stdbool.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
bool streql(const char* a, const char* b) {
    while (*a == *b && *a) {
        ++a;
        ++b;
    }
    return !*a && !*b;
}

#endif
