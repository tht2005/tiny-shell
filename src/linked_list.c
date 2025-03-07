#include "linked_list.h"

struct linked_list_node_t;
// struct linked_list_node_t {
//     void* ptr;
//     struct linked_list_node_t* prev;
//     struct linked_list_node_t* next;
// };

void linked_list_node_connect(struct linked_list_node_t* a, struct linked_list_node_t* b) {
    if(a) {
        a->next = b;
    }
    if(b) {
        b->prev = a;
    }
}

struct linked_list_node_t* new_linked_list_node(void* ptr) {
    struct linked_list_node_t* a = (struct linked_list_node_t*)malloc(sizeof(struct linked_list_node_t));
    if(a == NULL) {
        perror("Unable to create linked list node");
        exit(0);
    }
    a->ptr = ptr;
    a->prev = NULL;
    a->next = NULL;
    return a;
}

struct linked_list_node_t* create_linked_list() {
    struct linked_list_node_t* head = new_linked_list_node(NULL);
    struct linked_list_node_t* tail = new_linked_list_node(NULL);
    linked_list_node_connect(head, tail);
    return head;
}

void add_linked_list_front(struct linked_list_node_t* head, struct linked_list_node_t* node) {
    struct linked_list_node_t* next = head->next;
    linked_list_node_connect(head, node);
    linked_list_node_connect(node, next);
}

void add_linked_list_back(struct linked_list_node_t* tail, struct linked_list_node_t* node) {
    struct linked_list_node_t* prev = tail->prev;
    linked_list_node_connect(prev, node);
    linked_list_node_connect(node, tail);
}

void free_linked_list(struct linked_list_node_t* head) {
    struct linked_list_node_t* next;
    while(head) {
        next = head->next;
        if(head->ptr) {
            free(head->ptr);
        }
        free(head);
        head = next;
    }
}
