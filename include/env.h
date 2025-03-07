/**
 * @file
 * @brief Tiny shell's environment variables controller 
 */

#ifndef __ENV_H
#define __ENV_H

#include <string.h>

#include "dictionary.h"
#include "stack.h"

/**
 * @brief Init variable environment, should be called first in main()
 */
void env_init();

/**
 * @brief Get variable's value 
 *
 * @param key name of variable
 * @return variable's content
 */
char* env_getvar(char* key);

/**
 * @brief Assign new value to variable 
 *
 * @param key name of variable 
 * @param value variable's new value
 */
void env_putvar(char* key, char* value);

/**
 * @brief Push variable's value to stack and assign its value to empty string
 *
 * @param key name of variable 
 */
void env_pushvar(char* key);

/**
 * @brief Assign variable's value from stack top and pop an element of stack
 *
 * @param key name of variable 
 */
void env_popvar(char* key);

#endif
