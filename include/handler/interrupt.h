/**
 * @file
 * @brief Interupt handler
 */

#ifndef __INTERRUPT_H
#define __INTERRUPT_H

#include <signal.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief It must be runned at the beginning of this program
 */
void trigger_interrupt_handlers();

#endif
