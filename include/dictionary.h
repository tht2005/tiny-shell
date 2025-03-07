/**
 * @file
 * @brief Dictionary implementation, similar to unordered_map<string, string> in c++
 */

#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <stdint.h>
#include <string.h>

#include "custom_hash.h"
#include "hash_table.h"
#include "key_value.h"

typedef struct hash_table_t dictionary;

/**
 * @brief Dictionary instructor 
 *
 * @param HASHSIZE number of slot of hash table
 * @return an instance of dictionary
 */
dictionary* new_dictionary(uint64_t HASHSIZE);

/**
 * @brief Free memory
 *
 * @param dic 
 */
void free_dictionary(dictionary* dic);

/**
 * @brief Similar to dic[key] = value in c++
 *
 * @param dic 
 * @param key 
 * @param value 
 */
struct key_value* dictionary_put(dictionary* dic, char* key, char* value);

/**
 * @brief Similar to res = dic[key] in c++
 *
 * @param dic 
 * @param key 
 */
struct key_value* dictionary_get(dictionary* dic, char* key);

#endif
