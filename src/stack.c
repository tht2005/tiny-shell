#include "dalloc.h"
#include "stack.h"

struct stack_node_t;

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

void free_stack_node(struct stack_node_t* node) {
    free(node->ptr);
    free(node);
}

void* stack_top(struct stack_node_t** top) {
    if(*top == NULL) {
        perror("Can not access an empty stack");
        exit(1);
    }
    return (*top)->ptr;
}

void stack_push(struct stack_node_t** top, void* ptr) {
    struct stack_node_t* head = new_stack_node(ptr);
    head->next = (*top);
    (*top) = head;
}

void stack_pop(struct stack_node_t** top) {
    if(*top == NULL) {
        perror("Can not pop an empty stack");
        exit(1);
    }
    struct stack_node_t* head = (*top)->next;
    free_stack_node(*top);
    *top = head;
}

void free_stack(struct stack_node_t** top) {
    while(*top != NULL) {
        stack_pop(top);
    }
    free(*top);
}
