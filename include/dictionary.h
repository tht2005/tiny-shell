#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <stdint.h>
#include <string.h>

#include "custom_hash.h"
#include "hash_table.h"
#include "key_value.h"

typedef struct hash_table_t dictionary;

dictionary* new_dictionary(uint64_t HASHSIZE);

void free_dictionary(dictionary* dic);

struct key_value* dictionary_put(dictionary* dic, char* key, char* value);

struct key_value* dictionary_get(dictionary* dic, char* key);

#endif
