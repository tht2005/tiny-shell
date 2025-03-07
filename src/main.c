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

#include <assert.h>

int main(int argc, char** argv) {

    for(int i = 0; i < (int)1e5; ++i) {
        assert(
                custom_int_hash(i) ==custom_int_hash(i)
              );
    }

    printf("%lu %lu\n",
        custom_string_hash("abcdefgh"),
        custom_string_hash("abcdefgh")
    );

    printf("%lu %lu\n",
        custom_string_hash("abcdefgh"),
        custom_string_hash("abcdfghh")
    );

    printf("%lu %lu\n",
        custom_string_hash("abcfxxxgh"),
        custom_string_hash("abcfxxxgh")
    );
    
    return 0;
}
