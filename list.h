/******************************************************************************
 *
 *  -------------------------- list.h --------------------------------------- *
 *
 *****************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct node
{
    void* data;           // data held by node
    struct node* next;  // pointer to the next node
};

struct linked_list
{
    struct node* head;  // pointer to the head node
    struct node* tail;  // pointer to the head node
    int size;
    int (*match)(const void* key1, const void* key2);
    void (*destroy)(void* data);
};

struct linked_list* list_init(struct linked_list* list, void (*destroy)(void* data));

int list_destroy(struct linked_list* list);

int list_ins_next(struct linked_list* list, struct node* node, const void* data);

int list_push_back(struct linked_list* list, const void* data);

int list_rem_next(struct linked_list* list, struct node* node, void** data);

int list_for_each(struct linked_list* list, void (*callback)(void* data));

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, node) ((node) == (list)->node ? 1 : 0)

#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)

#define list_data(node) ((node)->data)

#define list_next(node) ((node)->next)

#endif
