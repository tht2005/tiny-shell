#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "version.h"
#include "hash_table.h"
#include "dalloc.h"

void init() {
    printf(TINY_SHELL" version %d.%d\n", TINY_SHELL_VERSION_MAJOR, TINY_SHELL_VERSION_MINOR);
}

char command[5000];

int main(int argc, char** argv) {

    init();
    
    while(1) {
        printf("tiny-shell> $ ");
        fgets(command, 4000, stdin);
        printf("Your command: %s\n", command);
        if(strcmp(command, "exit\n") == 0) {
            break;
        }
    }

    return 0;
}
