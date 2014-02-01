#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * This file contains the implementation of linked list functions
 * defined in linked_list.h.
 */


/**
 * Append a node to the linked list.
 */
int list_appendNode(struct linked_list* list, struct node* node)
{
    if (list == NULL)
    {
        // the list is invalid
        return E_INVALID_LIST;
    }
    
    if (node == NULL)
    {
        // the node is invalid
        return E_INVALID_NODE;
    }

    node->next = NULL;

    if (list->head == NULL)
    {
        // an empty list; insert at the head of the list
        list->head = node;
        list->tail = node;
        list->length = 1;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
        list->length ++;
    }

    return list->length;
}

/**
 * Delete the linked list.
 */
void list_free(struct linked_list* list)
{
    if (list != NULL)
    {
        struct node* node = list->head;
        struct node* temp = NULL;

        while (node != NULL)
        {
            temp = node;
            node = node->next;
            free(temp);
        }

        free(list);
    }
}

/**
 * Return the data at the specified index in the linked list.
 */
int* list_getData(struct linked_list* list, int index)
{
    if ( list_isEmpty(list) || (index < 0 || index >= list_length(list)) )
    {
        // the list is either empty or the index is out of range
        return NULL;
    }

    struct node* node = list->head;
    int count = 0;

    while (count < index)
    {
        node = node->next;
        count++;
    }

    return &(node->data);
}

/**
 * Initialize a linked list.
 */
struct linked_list* list_init()
{
    struct linked_list* list = (struct linked_list*)malloc(sizeof(struct linked_list));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
    }

    return list;
}

/**
 * Returns TRUE if the linked list is empty.
 */
bool list_isEmpty(struct linked_list* list)
{
    return ( (list == NULL) || (list->head == NULL) );
}

/**
 * Returns the length of the linked list.
 */
int list_length(struct linked_list* list)
{
    return list ? list->length : -1;
}

/**
 * Allocate a node with the specified data.
 */
struct node* list_mallocNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    if (node == NULL)
    {
        printf("Error allocating memory for node.  Exiting.\n");
        exit(-1);
    }

    node->data = data;
    node->next = NULL;

    return node;
}

/**
 * Print a linked list.
 */
void list_print(struct linked_list* list)
{
    //printf("[");

    if (list != NULL)
    {
        struct node* node = list->head;

        while (node != NULL)
        {
            //printf(" %d", node->data);
            node = node->next;
        }
    }

    //printf(" ]\n");
}