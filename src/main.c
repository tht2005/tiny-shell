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

    for(int i = 0; i < 10; ++i) {
        int* a = (int *)dalloc(sizeof(int));
        *a = i;
        stack_push(&stk, (void*)a);
    }

    while(stk) {
        int val = *(int*)(stk->ptr);
        printf("%d\n", val);
        stack_pop(&stk);
    }

    free_stack(&stk);

    return 0;
}
