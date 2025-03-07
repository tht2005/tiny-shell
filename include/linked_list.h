#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stdlib.h>
#include <unistd.h>

struct linked_list_node_t {
    void* ptr;
    struct linked_list_node_t* prev;
    struct linked_list_node_t* next;
};

void linked_list_node_connect(struct linked_list_node_t*,
                                struct linked_list_node_t*);

struct linked_list_node_t* new_linked_list_node(void*);

struct linked_list_node_t* create_linked_list();

void add_linked_list_front(struct linked_list_node_t*,
                struct linked_list_node_t*);
void add_linked_list_back(struct linked_list_node_t*,
                struct linked_list_node_t*);

void free_linked_list(struct linked_list_node_t*);

#endif
