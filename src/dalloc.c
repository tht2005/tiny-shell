#include "dalloc.h"

void* dalloc(size_t size) {
    void* a = malloc(size);
    if(a == NULL) {
        perror("Can not create array");
        exit(1);
    }
    return a;
}

void* drealloc(void* ptr, size_t size) {
    void* a = realloc(ptr, size);
    if(a == NULL) {
        perror("Can not resize array");
        exit(1);
    }
    return a;
}
