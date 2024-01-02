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
    const unsigned long long* aq = (const unsigned long long*)a;
    const unsigned long long* bq = (const unsigned long long*)b;
    while (*aq && *aq == *bq) {
        ++aq;
        ++bq;
    }
    const unsigned long* ad = (const unsigned long*)aq;
    const unsigned long* bd = (const unsigned long*)bq;
    while (*ad && *ad == *bd) {
        ++ad;
        ++bd;
    }
    const unsigned short* aw = (const unsigned short*)ad;
    const unsigned short* bw = (const unsigned short*)bd;
    while (*aw && *aw == *bw) {
        ++aw;
        ++bw;
    }
    a = (const char*)aw;
    b = (const char*)bw;
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    return !*b;
}

#endif
