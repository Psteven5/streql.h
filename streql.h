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
    const uint64_t* aq2 = aq;
    const uint64_t* bq2 = bq;
    while (*aq && *aq == *bq) {
        ++aq;
        ++bq;
    }
    const uint32_t* ad = (const uint32_t*)(aq > aq2 ? --aq : aq2);
    const uint32_t* bd = (const uint32_t*)(bq > bq2 ? --bq : bq2);
    const uint32_t* ad2 = ad;
    const uint32_t* bd2 = bd;
    while (*ad && *ad == *bd) {
        ++ad;
        ++bd;
    }
    const uint16_t* aw = (const uint16_t*)(ad > ad2 ? --ad : ad2);
    const uint16_t* bw = (const uint16_t*)(bd > bd2 ? --bd : bd2);
    const uint16_t* aw2 = aw;
    const uint16_t* bw2 = bw;
    while (*aw && *aw == *bw) {
        ++aw;
        ++bw;
    }
    a = (const char*)(aw > aw2 ? --aw : aw2);
    b = (const char*)(bw > bw2 ? --bw : bw2);
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    return !*a && !*b;
}

#endif
