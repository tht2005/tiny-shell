#include "interrupt.h"

void sigint_handler() {
    puts("SIGINT");
    exit(1);
}

void sigquit_handler() {
    puts("SIGQUIT");
    exit(1);
}

void sigtstp_handler() {
    puts("SIGTSTP");
    exit(1);
}

void trigger_interrupt_handlers() {
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGTSTP, sigtstp_handler);
}
