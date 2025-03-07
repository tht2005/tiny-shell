#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "version.h"

#include "dalloc.h"
#include "hash_table.h"
#include "void_stack.h"

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

    struct keyvalue* kv;
    struct linked_list_node_t* ptr;

    kv = new_keyvalue("abcd", "an ba to com");
    hash_table_put(a, kv, hash, keyvalue_cmp);

    kv = new_keyvalue("abcd", "an ba to com");
    ptr = hash_table_look_up(a, kv, hash, keyvalue_cmp);
    free(kv);
    printf("debug: %s\n", (ptr) ? (char*)(((struct keyvalue *)ptr->ptr)->value) : "(null)");

    kv = new_keyvalue("abcde", "an ba to com");
    ptr = hash_table_look_up(a, kv, hash, keyvalue_cmp);
    free(kv);
    printf("debug: %s\n", (ptr) ? (char*)(((struct keyvalue *)ptr->ptr)->value) : "(null)");

    kv = new_keyvalue("abcd", "an hai to com thoi");
    hash_table_put(a, kv, hash, keyvalue_cmp);

    kv = new_keyvalue("abcd", "an ba to com");
    ptr = hash_table_look_up(a, kv, hash, keyvalue_cmp);
    free(kv);
    printf("debug: %s\n", (ptr) ? (char*)(((struct keyvalue *)ptr->ptr)->value) : "(null)");

    free_hash_table(a);

    return 0;
}
