#include "dalloc.h"
#include "stack.h"

struct stack_node_t {
    void* ptr;
    struct stack_node_t* next;
};

void* stack_top(stack_t* stk) {
    if(*stk == NULL) {
        perror("Can not access an empty stack");
        exit(1);
    }
    return (*stk)->ptr;
}

struct stack_node_t* new_stack_node(void* ptr) {
    struct stack_node_t* a = (struct stack_node_t *)malloc(sizeof(struct stack_node_t));
    if(a == NULL) {
        perror("Unable to create stack node");
        exit(1);
    }
    a->ptr = ptr;
    a->next = NULL;
    return a;
}

void stack_push(stack_t* stk, void* ptr) {
    struct stack_node_t* head = new_stack_node(ptr);
    head->next = *stk;
    *stk = head;
}

void stack_pop(stack_t* stk) {
    if(*stk == NULL) {
        perror("Can not pop an empty stack");
        exit(1);
    }
    struct stack_node_t* head = (*stk)->next;
    free(*stk);
    *stk = head;
}

stack_t* new_stack() {
    return NULL;
}
void free_stack(stack_t* stk) {
    while(*stk != NULL) {
        stack_pop(stk);
    }
}
