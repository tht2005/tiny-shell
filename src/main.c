#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "version.h"

#include "dalloc.h"
#include "hash_table.h"
#include "stack.h"

#include "dictionary.h"

#include "env.h"
#include "interrupt.h"

#include <assert.h>

void init() {
    env_init();
    trigger_interrupt_handlers();

    // print message ...
}

void loop() {
    char command[500];
    while(1) {
        printf("%s", env_getvar("PS1"));
        fgets(command, 400, stdin);
    }
}

int main(int argc, char** argv) {
    init();
    loop();
    return 0;
}
