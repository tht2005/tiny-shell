#include "key_value.h"

struct key_value;

struct key_value* new_key_value(char* key, char* value) {
    struct key_value* a = (struct key_value *)malloc(sizeof(struct key_value));
    if(a == NULL) {
        perror("Can not create key value");
        exit(1);
    }
    a->key = key;
    a->value = value;
    return a;
}

void free_key_value(struct key_value* a) {
    if(a->key) {
        free(a->key);
    }
    if(a->value) {
        free(a->value);
    }
    free(a);
}

struct key_value * dup_key_value(struct key_value * kv) {
    char* key = strdup(kv->key);
    char* value = strdup(kv->value);
    return new_key_value(key, value);
}
