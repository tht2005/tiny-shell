#ifndef __DINPUT_H
#define __DINPUT_H

#include <stdio.h>

#include "dalloc.h"

char* dfgets(FILE* stream);

char** get_args(char* cmd);

#endif
