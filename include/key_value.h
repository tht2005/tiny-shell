#ifndef __KEY_VALUE_H
#define __KEY_VALUE_H

#include <stdlib.h>
#include <stdio.h>

struct key_value {
    char* key;
    char* value;
};

struct key_value* new_key_value(char* key, char* value);

void free_key_value(struct key_value* a);

#endif
