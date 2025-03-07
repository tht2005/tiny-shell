#include "dalloc.h"
#include "hash_table.h"

struct hash_table_t;
// struct hash_table_t {
//     unsigned HASHSIZE;
//     struct linked_list_node_t** hashtab;
// };

struct hash_table_t* new_hash_table(unsigned HASHSIZE) {
    if(HASHSIZE == 0) {
        perror("Can't create a hash table with HASHSIZE=0");
        exit(0);
    }
    struct hash_table_t* a = (struct hash_table_t*)malloc(sizeof(struct hash_table_t));
    if(a == NULL) {
        perror("Unable to create hash table");
        exit(0);
    }
    a->HASHSIZE = HASHSIZE;
    a->hashtab = (struct linked_list_node_t** ) dalloc(HASHSIZE * sizeof (struct linked_list_node_t* ));
    int i;
    for(i = 0; i < HASHSIZE; ++i) {
        a->hashtab[i] = create_linked_list();
    }
    return a;
}
void free_hash_table(struct hash_table_t* a) {
    int i;
    for(i = 0; i < a->HASHSIZE; ++i) {
        free_linked_list(a->hashtab[i]);
    }
    free(a->hashtab);
    free(a);
}

struct linked_list_node_t* hash_table_look_up(struct hash_table_t* a, void* obj, unsigned (*hash)(void*), int (*cmp)(void*, void*)) {
    int slot = hash(obj) % (a->HASHSIZE);
    struct linked_list_node_t* ptr;
    for(ptr = a->hashtab[slot]; ptr; ptr = ptr->next) {
        if(ptr->ptr && cmp(ptr->ptr, obj) == 0) {
            return ptr;
        }
    }
    return NULL;
}

struct linked_list_node_t* hash_table_put(struct hash_table_t* a, void* obj, unsigned (*hash)(void*), int (*cmp)(void*, void*), void* (*dup)(void*)) {
    struct linked_list_node_t* ptr = hash_table_look_up(a, obj, hash, cmp);
    int slot;
    if(ptr == NULL) {
        ptr = new_linked_list_node(NULL); 
        slot = hash(obj) % (a->HASHSIZE);
        add_linked_list_front(a->hashtab[slot], ptr);
    }
    else {
        free(ptr->ptr);
    }
    ptr->ptr = dup(obj);
    return ptr;
}
