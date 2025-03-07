#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

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
    while(1) {
        printf("%s", env_getvar("PS1"));
        char* cmd = dfgets(stdin);
        printf("your cmd: %s\n", cmd);
        int cmp = strcmp(cmd, "exit");
        free(cmd);
        if(cmp == 0) {
            break;
        }
    }
}

int main(int argc, char** argv) {
    init();
    loop();
    return 0;
}
