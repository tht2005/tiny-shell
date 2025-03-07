#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "version.h"
#include "hash_table.h"
#include "dalloc.h"

struct keyvalue {
    char* key;
    char* value;
};
struct keyvalue* new_keyvalue(char* key, char* value) {
    struct keyvalue* a = (struct keyvalue *) dalloc(sizeof(struct keyvalue));
    a->key = key;
    a->value = value;
    return a;
}

void* keyvalue_dup(void* obj) {
    return (void *)
        new_keyvalue(((struct keyvalue*)obj)->key, ((struct keyvalue *)obj)->value);
}

int keyvalue_cmp(void* a, void* b) {
    return strcmp(
        ((struct keyvalue *)a)->key,
        ((struct keyvalue *)b)->key
    );
}

unsigned hash(void* obj) {
    char* s = ((struct keyvalue *)obj)->key;
    unsigned res = 0;
    for(; *s; ++s) {
        res = res * 311 + *s + 1;
    }
    return res;
}

char command[5000];

int main(int argc, char** argv) {

    struct hash_table_t* a = new_hash_table(1<<15);

    hash_table_put(a, new_keyvalue("abcd", "an ba to com"), hash, keyvalue_cmp, keyvalue_dup);

    free_hash_table(a);

    return 0;
}
