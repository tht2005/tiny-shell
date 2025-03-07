#ifndef __STACK_H
#define __STACK_H

#include <stdlib.h>
#include <stdio.h>

struct stack_node_t;
// struct stack_node_t {
//     void* ptr;
//     struct stack_node_t* next;
// };

typedef struct stack_node_t* stack_t;

stack_t* new_stack();
void free_stack(stack_t* stk);

void* stack_top(stack_t* stk);

void stack_push(stack_t* stk, void* ptr);
void stack_pop(stack_t* stk);

#endif
