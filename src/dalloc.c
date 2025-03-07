#include "dalloc.h"

void* dalloc(size_t size) {
    void* a = malloc(size);
    if(a == NULL) {
        perror("Can not create array");
        exit(0);
    }
    return a;
}
