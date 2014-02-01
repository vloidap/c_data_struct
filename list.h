#include <stdbool.h>

#define E_NO_ERROR       0
#define E_INVALID_LIST     -1
#define E_INVALID_NODE     -2
#define E_OUT_OF_RANGE -10

/**
 * Represents one node in the linked list.
 */
struct node
{
    int data;           // data held by node
    struct node* next;  // pointer to the next node
};

/**
 * Represents a linked list data structure.
 */
struct linked_list
{
    struct node* head;  // pointer to the head node
    struct node* tail;  // pointer to the head node
    int length;
};

/**
 * Function prototypes
 */
int list_appendList(struct linked_list* list1, struct linked_list* list2);
int list_appendNode(struct linked_list* list, struct node* node);
struct linked_list* list_copy(struct linked_list* list);
void list_free(struct linked_list* list);
int* list_getData(struct linked_list* list, int index);
struct linked_list* list_init();
int list_insertNode(struct linked_list* list, struct node* node, int index);
bool list_isEmpty(struct linked_list* list);
int list_length(struct linked_list* list);
struct node* list_mallocNode(int data);
void list_print(struct linked_list* list);
struct node* list_removeNode(struct linked_list* list, int index);
void list_reverse(struct linked_list* list);