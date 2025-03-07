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
    free(a->key);
    free(a->value);
    free(a);
}
