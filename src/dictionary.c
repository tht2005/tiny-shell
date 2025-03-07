#include "dictionary.h"

// local

void free_dictionary_element(void* ptr) {
    free_key_value( (struct key_value *)ptr );
}
uint64_t key_value_hash(void* ptr) {
    return custom_string_hash(
        ( (struct key_value *)ptr ) ->key
    );
}
int key_value_cmp(void* a, void *b) {
    return strcmp(
        ( (struct key_value *)a ) ->key,
        ( (struct key_value *)b ) ->key
    );
}

// global

dictionary* new_dictionary(uint64_t HASHSIZE) {
    return new_hash_table(HASHSIZE);
}

void free_dictionary(dictionary* dic) {
    free_hash_table(dic, free_dictionary_element);
}

struct key_value* dictionary_put(dictionary* dic, char* key, char* value) {
    struct key_value* kv = new_key_value(key, value);
    struct linked_list_node_t* node = hash_table_put(dic, (void*)kv, key_value_hash, key_value_cmp, free_dictionary_element); 
    return (struct key_value *) (node->ptr);
}

struct key_value* dictionary_get(dictionary* dic, char* key) {
    struct key_value kv = { key, NULL };
    struct linked_list_node_t* node = hash_table_look_up(dic, (void *) (&kv), key_value_hash, key_value_cmp);
    return ( node == NULL )
            ? NULL
            : ( struct key_value* ) (node->ptr);
}
