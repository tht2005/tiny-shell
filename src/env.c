#include "env.h"

// variables

#define HASHSIZE (1<<10)

const char* EMPTY_STR = "";

dictionary* dic = NULL;
struct stack_node_t* stk = NULL;

// functions

void free_stack_element(void* ptr) {
    free_key_value( (struct key_value *)ptr );
}

void env_exit() {
    free_dictionary(dic);
    free_stack(&stk, free_stack_element);
}

// temporary function, it shound be in string_utils.h
char* new_str(const char* s) {
    char* a = (char *) dalloc( (strlen(s) + 1) * sizeof(char) );
    strcpy(a, s);
    return a;
}

// global functions

void env_init() {
    dic = new_dictionary(HASHSIZE);
    stk = NULL;

    // source profile from ...

    // temporary commands ...
    env_putvar(new_str("PS1"), new_str("tiny-shell> $ "));

    atexit(env_exit);
}

char* env_getvar(char* key) {
    struct key_value* kv = (struct key_value *) dictionary_get(dic, key);
    if(kv == NULL) {
        return (char *) EMPTY_STR;
    }
    return (char *) kv->value;
}

void env_putvar(char* key, char* value) {
    dictionary_put(dic, key, value);
}

void env_pushvar(char* key) {
    struct key_value* ret = (struct key_value *) dictionary_get(dic, key);

    struct key_value* kv =new_key_value(strdup(key),
                                        (ret == NULL) ? strdup(EMPTY_STR) : strdup((char*) ret->value));
    stack_push(&stk, (void*) kv);

    env_putvar(
        strdup(key),
        strdup(EMPTY_STR)
    );
}

void env_popvar(char* key) {
    if(stk == NULL) {
        perror("Environment: can not pop var when stack is empty");
        exit(1);
    }
    struct key_value* kv = (struct key_value *) stack_top(&stk);
    if(kv == NULL || kv->key == NULL || kv->value == NULL) {
        perror("Impossible!! Env stack top or its attributes can not be NULL");
        exit(1);
    }
    if(strcmp(key, (char *)kv->key) != 0) {
        perror("Developer!! There is a bug in env_popvar()");
        exit(1);
    }
    env_putvar(strdup(key), strdup((char *) kv->value));
    // must be called last because it free some memory ...
    stack_pop(&stk, free_stack_element);
}

