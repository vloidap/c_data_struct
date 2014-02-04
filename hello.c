#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "list.h"

void destroy(void* data) {
  free(data);
}

int main(int argc, char** argv)
{
    struct linked_list list;
    int i = 0;
    struct timeval tv;

    printf("Creating a new linked list:\n");
    struct linked_list* plist = list_init(&list, destroy);
    if (plist) {
      printf("\nAppending 1 000 000 nodes to the linked list:\n");
      gettimeofday(&tv,NULL);
      unsigned long start = 1000000 * tv.tv_sec + tv.tv_usec;
      for (i = 0; i < 1000000; i++)
      {
        char* data = (char*)malloc(32);
        strcpy(data, "Hello, world!");
        list_push_back(plist, data);         
      }
      
      gettimeofday(&tv,NULL);
      unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;
      list_destroy(plist);
      printf ("%ld micro seconds\n", end - start);
    }
    return 0;
}
