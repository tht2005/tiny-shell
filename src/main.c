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

#include <assert.h>

char* create_string() {
    char* a = (char* ) dalloc(50 * sizeof(char));
    for(int i = 0; i < 10; ++i) {
        a[i] = custom_int_hash(rand()) % 26 + 'a';
    }
    a[10] = 0;
    printf("debug: %s\n", a);
    return a;
}

char s[50];

int main(int argc, char** argv) {

    srand(time(NULL));

    dictionary* dic = new_dictionary(1<<16);

    dictionary_put(dic, create_string(), create_string());
    dictionary_put(dic, create_string(), create_string());
    dictionary_put(dic, create_string(), create_string());
    dictionary_put(dic, create_string(), create_string());

    struct key_value *kv;

    scanf("%s", s);
    kv = dictionary_get(dic, s);
    printf("%s\n", (kv == NULL) ? "(null)" : (char*)kv->value);

    dictionary_put(dic, strdup(s), create_string());
    kv = dictionary_get(dic, s);
    printf("%s\n", (kv == NULL) ? "(null)" : (char*)kv->value);
    
    free_dictionary(dic);
    
    return 0;
}
