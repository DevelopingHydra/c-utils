#ifndef GENERICLINKESLIST_H
#define GENERICLINKESLIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_list_element{
    void* data;
    int dataTypeSize;
    struct linked_list_element* nextElement;
    struct linked_list_element* beforeElement;
} LinkedListElement;

typedef enum {
    LINKED_LIST_RESPONSE_error, LINKED_LIST_RESPONSE_ok
} linked_list_response;

LinkedListElement* create_linked_list(int dataTypeSize, void* data);
void ll_destroy_all(LinkedListElement* list);

linked_list_response ll_get(LinkedListElement* list, int index, void* returnElement);

linked_list_response ll_add(LinkedListElement* list, void* data);

linked_list_response ll_remove(LinkedListElement* list, void* data);
linked_list_response ll_remove_at(LinkedListElement* list, int index);

linked_list_response ll_contains(LinkedListElement* list, void* data, bool* result);

linked_list_response ll_size(LinkedListElement* list, int* size);

LinkedListElement* getHead(LinkedListElement* list, int* traversedElements);
LinkedListElement* getTail(LinkedListElement* list, int* travesedElements);

#endif /* GENERICARRAYLIST_H */


