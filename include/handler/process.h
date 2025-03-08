#ifndef __PROCESS_H
#define __PROCESS_H

#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

enum run_mode {
    FOREGROUND_MODE,
    BACKGROUND_MODE
};

// void create_new_process(enum run_mode rm) {
//
// }

#endif
