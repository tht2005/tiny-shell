/**
 * @file
 * @brief library for hashing
 */

#ifndef CUSTOM_HASH_H
#define CUSTOM_HASH_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include <sys/time.h>

/**
 * @brief It can be consider a random mapping f(x) between two integer sets
 *
 * @param x
 * @return f(x)
 */
uint64_t custom_int_hash(uint64_t x);

/**
 * @brief String hashing
 *
 * @param str string
 * @return hash value
 */
uint64_t custom_string_hash(char* str);

#endif
