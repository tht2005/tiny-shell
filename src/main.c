#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "version.h"

int main() {

    printf("%d %d\n", TINY_SHELL_VERSION_MAJOR, TINY_SHELL_VERSION_MINOR);

    while(1) {
        printf("tiny-shell> $ ");
        char s[500];
        scanf("%s", s);
    }

    return 0;
}
