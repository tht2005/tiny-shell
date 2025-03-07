#ifndef CUSTOM_HASH_H
#define CUSTOM_HASH_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include <sys/time.h>

uint64_t time_since_epoch();

uint64_t splitmix64(uint64_t x);

const size_t custom_digit_hash(uint64_t x);

#endif
