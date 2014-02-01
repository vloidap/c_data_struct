#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "list.h"

/**
 * Sample driver program to test some linked list functions.
 */

int main(int argc, char** argv)
{
    struct linked_list* list = NULL;
    struct node* node = NULL;
    int i = 0;
    struct timeval tv;

    printf("Creating a new linked list:\n");
    list = list_init();
    printf("\nAppending 1 000 000 nodes to the linked list:\n");
    gettimeofday(&tv,NULL);
    unsigned long start = 1000000 * tv.tv_sec + tv.tv_usec;
    for (i = 0; i < 1000000; i++)
    {
        node = list_mallocNode(i);
        list_appendNode(list, node);
    }
    
    list_print(list);
    gettimeofday(&tv,NULL);
    unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;
    list_free(list);
    printf ("%ld micro seconds\n", end - start);

    return 0;
}