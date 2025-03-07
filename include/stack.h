/**
 * @file
 * @brief Stack implementation
 */

#ifndef __STACK_H
#define __STACK_H

#include <stdlib.h>
#include <stdio.h>

struct stack_node_t {
    void* ptr;
    struct stack_node_t* next;
};

void* stack_top(struct stack_node_t** top);

void stack_push(struct stack_node_t** top, void* ptr);

void stack_pop(struct stack_node_t** top, void (*free_ptr)(void*) );

void free_stack(struct stack_node_t** top, void (*free_ptr)(void*) );

#endif
