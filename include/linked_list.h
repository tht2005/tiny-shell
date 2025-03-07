/**
 * @file
 * @brief Implementation of linked list
 */

#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct linked_list_node_t {
    void* ptr;
    struct linked_list_node_t* prev;
    struct linked_list_node_t* next;
};

/**
 * @brief Connect to linked list node a and b, a -> b
 *
 * @param a 
 * @param b 
 */
void linked_list_node_connect(struct linked_list_node_t* a,
                                struct linked_list_node_t* b);

/**
 * @brief Create a new linked list node
 *
 * @param ptr linked list node's content
 */
struct linked_list_node_t* new_linked_list_node(void* ptr);

/**
 * @brief Create an empty linked list (an empty linked list contain two empty node head and tail)
 *
 */
struct linked_list_node_t* create_linked_list();

/**
 * @brief Add a new node to the front of the linked list
 *
 * @param head 
 * @param node 
 */
void add_linked_list_front(struct linked_list_node_t* head,
                            struct linked_list_node_t* node);

/**
 * @brief Add a new node to the back of the linked list
 *
 * @param tail 
 * @param node 
 */
void add_linked_list_back(struct linked_list_node_t* tail,
                            struct linked_list_node_t* node);

/**
 * @brief Free a linked list
 *
 * @param head head of the linked list
 * @param free_ptr function to free linked list node's ptr
 */
void free_linked_list(struct linked_list_node_t* head, void (*free_ptr)(void*));

#endif
