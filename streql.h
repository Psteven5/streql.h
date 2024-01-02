#ifndef STREQL
#define STREQL

#include <stdbool.h>
#include <stdint.h>

/*
Checks for equality between two null-terminated strings 'a' and 'b'.
Meant for long strings.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    const unsigned long long* _a = (const unsigned long long*)a;
    const unsigned long long* _b = (const unsigned long long*)b;
    while (*_a && *_a == *_b) {
        ++_a;
        ++_b;
    }
    const unsigned long* __a = (const unsigned long*)_a;
    const unsigned long* __b = (const unsigned long*)_b;
    while (*__a && *__a == *__b) {
        ++__a;
        ++__b;
    }
    const unsigned short* _a_ = (const unsigned short*)__a;
    const unsigned short* _b_ = (const unsigned short*)__b;
    while (*_a_ && *_a_ == *_b_) {
        ++_a_;
        ++_b_;
    }
    a = (const char*)_a_;
    b = (const char*)_b_;
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    return !*b;
}

#endif
