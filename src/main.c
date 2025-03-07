#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "version.h"

#include "dalloc.h"
#include "hash_table.h"
#include "stack.h"

#include "custom_hash.h"

int main(int argc, char** argv) {

    for(int i = 0; i < (int)1e5; ++i) {
        custom_digit_hash(i);
    }
    
    return 0;
}
