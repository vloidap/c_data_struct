#include <stdlib.h>
#include <string.h>
#include "list.h"

struct linked_list* list_init(struct linked_list* list, void (*destroy)(void* data)) {
  if (list) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
  }
  return list;
}

int list_destroy(struct linked_list* list) {
  if (list == NULL) 
    return -1;
  void* data;
  while (list_size(list) > 0) {
    if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(struct linked_list));
  return 0;
}

int list_push_back(struct linked_list* list, const void* data) {
  return list_ins_next(list, list->tail, data);
}
 
int list_ins_next(struct linked_list* list, struct node* node, const void* data) {
  if (list == NULL)
    return -1;
  struct node* new_node;
  if ((new_node = (struct node*)malloc(sizeof(struct node))) == NULL)
    return -1;

  new_node->data = (void*)data;
  if (node == NULL) {
    if (list_size(list) == 0)
      list->tail = new_node;

    new_node->next = list->head;
    list->head = new_node;
  } else {
    if (node->next == NULL)
      list->tail = new_node;

    new_node->next = node->next;
    node->next = new_node;
  }

  list->size++;
  return 0;
}

int list_rem_next(struct linked_list* list, struct node* element, void** data) {
  if (list == NULL)
    return -1;
  struct node* old_element;
  if (list_size(list) == 0)
    return -1;

  if (element == NULL) {
    *data = list->head->data;
    old_element = list->head;
    list->head = list->head->next;

    if (list_size(list) == 1)
      list->tail = NULL;
  } else {
    if (element->next == NULL)
      return -1;
    *data = element->next->data;
    old_element = element->next;
    element->next = element->next->next;

    if (element->next == NULL)
      list->tail = element;
  }

  free(old_element);

  list->size --;

  return 0;
}


int list_for_each(struct linked_list* list, void (*callback)(void* data)) {
  if (list == NULL || callback == NULL)
    return -1;
  void* data;
  struct node* node = list_head(list);
  while (node) {
    callback(list_data(node));
    node = list_next(node);
  }
}
