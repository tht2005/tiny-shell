#ifndef __KEY_VALUE_H
#define __KEY_VALUE_H

#include <stdlib.h>
#include <stdio.h>

#include <string.h>
// #include "string_utils.h"

struct key_value {
    char* key;
    char* value;
};

struct key_value* new_key_value(char* key, char* value);

void free_key_value(struct key_value* a);

struct key_value* dup_key_value(struct key_value* kv);

#endif
