#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "version.h"
#include "linked_list.h"

void init() {
    printf(TINY_SHELL" %d.%d\n", TINY_SHELL_VERSION_MAJOR, TINY_SHELL_VERSION_MINOR);
}

int main(int argc, char** argv) {

    init();

    while(1) {
        printf("tiny-shell> $ ");
        char s[500];
        scanf("%s", s);
    }

    return 0;
}
