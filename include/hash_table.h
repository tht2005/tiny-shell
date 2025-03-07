/**
 * @file
 * @brief Implementation of hash table
 */

#ifndef __HASH_TABLE_H
#define __HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "dalloc.h"
#include "linked_list.h"

struct hash_table_t {
    uint64_t HASHSIZE;
    struct linked_list_node_t** hashtab;
};

/**
 * @brief Create a new hash table with HASHSIZE slot
 *
 * @param HASHSIZE 
 */
struct hash_table_t* new_hash_table(uint64_t HASHSIZE);

/**
 * @brief Free a hash table
 *
 * @param a pointer to hash table
 * @param free_ptr function to free hash table's content
 */
void free_hash_table(struct hash_table_t* a, void (*free_ptr)(void*));

/**
 * @brief Hash table key look up
 *
 * @param a hash table
 * @param obj value to look up
 * @param hash function to calculate obj's hash value
 * @param cmp compare function, it should return zero if its parameters is considered equal
 */
struct linked_list_node_t* hash_table_look_up(struct hash_table_t* a, void* obj, uint64_t (*hash)(void*), int (*cmp)(void*, void*));

/**
 * @brief Hash table insert key
 *
 * @param a hash table 
 * @param obj value to insert
 * @param hash function to calculate obj's hash value
 * @param cmp compare function, it should return zero if its parameters is considered equal
 * @param free_ptr function to free the replaced value
 */
struct linked_list_node_t* hash_table_put(struct hash_table_t* a, void* obj, uint64_t (*hash)(void*), int (*cmp)(void*, void*), void (*free_ptr)(void*)); 

#endif
