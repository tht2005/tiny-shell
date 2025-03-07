#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "version.h"

#include "dalloc.h"
#include "hash_table.h"
#include "stack.h"

char command[5000];

int main(int argc, char** argv) {
    
    struct stack_node_t* stk = NULL;

    for(int i = 0; i < 100; ++i) {
        int* a = (int*)dalloc(10 * sizeof(int));
        stack_push(&stk, (void*)a);
    }
    for(int i = 0; i < 1000; ++i) {
        stack_top(&stk);
    }

    for(int i = 0; i < 50; ++i) {
        stack_pop(&stk);
    }
    for(int i = 0; i < 1000; ++i) {
        stack_top(&stk);
    }

    for(int i = 0; i < 100; ++i) {
        int* a = (int*)dalloc(10 * sizeof(int));
        stack_push(&stk, (void*)a);
    }

    for(int i = 0; i < 1000; ++i) {
        stack_top(&stk);
    }

    for(int i = 0; i < 99; ++i) {
        stack_pop(&stk);
    }
    for(int i = 0; i < 1000; ++i) {
        stack_top(&stk);
    }

    free_stack(&stk);

    for(int i = 0; i < 1000; ++i) {
        stack_top(&stk);
    }

    return 0;
}
