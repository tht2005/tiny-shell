#ifndef __ALLOC_H
#define __ALLOC_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Wrapper for malloc
 *
 * @param size 
 */
void* alloc(size_t size) {
    void* a = malloc(size);
    if(a == NULL) {
        perror("Can not create array");
        exit(0);
    }
    return a;
}

#endif
