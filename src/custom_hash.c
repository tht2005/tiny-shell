#include "custom_hash.h"

uint64_t time_since_epoch() {
    struct timeval tv;

    gettimeofday(&tv, NULL);

    unsigned long long millisecondSinceEpoch =
        (unsigned long long)(tv.tv_sec) * 1000 +
        (unsigned long long)(tv.tv_usec) / 1000;

    return millisecondSinceEpoch;
}

uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += (uint64_t)0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * (uint64_t)0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * (uint64_t)0x94d049bb133111eb;
    return x ^ (x >> 31);
}

uint64_t FIXED_RANDOM = 0;

const size_t custom_digit_hash(uint64_t x) {
    if(FIXED_RANDOM == 0) {
        FIXED_RANDOM = time_since_epoch();
        printf("debug: %lu\n", FIXED_RANDOM);
    }
    if(FIXED_RANDOM == 0) {
        perror("custom_hash.h::time_since_epoch() generate 0!");
        exit(1);
    }
    return splitmix64(x + FIXED_RANDOM);
}
