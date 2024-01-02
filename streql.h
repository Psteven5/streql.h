#ifndef STREQL
#define STREQL

#include <stdbool.h>
#include <stdint.h>

/*
-- Only worth using for longer strings. --
Checks for equality between two null-terminated strings 'a' and 'b'.
Returns 1 if equal, else 0.
*/
static inline bool streql(const char* a, const char* b) {
    const uint64_t* aq = (const uint64_t*)a;
    const uint64_t* bq = (const uint64_t*)b;
    while (*aq && *aq == *bq) {
        ++aq;
        ++bq;
    }
    const uint32_t* ad = (const uint32_t*)--aq;
    const uint32_t* bd = (const uint32_t*)--bq;
    while (*ad && *ad == *bd) {
        ++ad;
        ++bd;
    }
    const uint16_t* aw = (const uint16_t*)--ad;
    const uint16_t* bw = (const uint16_t*)--bd;
    while (*aw && *aw == *bw) {
        ++aw;
        ++bw;
    }
    a = (const char*)--aw;
    b = (const char*)--bw;
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    return !*a && !*b;
}

#endif
