#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "config.h"

#include "dalloc.h"
#include "hash_table.h"
#include "stack.h"

#include "dictionary.h"

#include "env.h"
#include "interrupt.h"
#include "dinput.h"

#include <assert.h>

#include <ctype.h>

void init() {
    env_init();
    trigger_interrupt_handlers();

    // print message ...
    //
}

void loop() {

    pid_t cpid = fork();
    if(cpid == -1) {
        //
        exit(EXIT_FAILURE);
    }

    return ;

    while(1) {
        printf("%s", env_getvar("PS1"));
        char* cmd = dfgets(stdin);

        char *token;
        char *rest = cmd;

        printf("[ ");
        while((token = strtok_r(rest, " \t\n\v\f\r", &rest))) {
            printf("%s, ", token);
        }
        printf("]\n");

        free(cmd);
    }
}

int main(int argc, char** argv) {
    init();
    loop();
    return 0;
}
