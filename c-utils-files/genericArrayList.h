
#ifndef GENERICARRAYLIST_H
#define GENERICARRAYLIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int size;
    int indexTop;
    void* array;
    int dataTypeSize;
} ArrayList;

typedef enum {
    ARRAY_LIST_error, ARRAY_LIST_ok
} array_list_response;

ArrayList* create_array_list(int dataTypeSize);
void al_destroy(ArrayList* list);

array_list_response al_get(ArrayList* list, int index, void* returnElement);

array_list_response al_add(ArrayList* list, void* data);
array_list_response al_set(ArrayList* list, void* data, int index);

array_list_response al_remove(ArrayList* list, void* data);
array_list_response al_remove_at(ArrayList* list, int index);

array_list_response al_contains(ArrayList* list, void* data, bool* result);

array_list_response al_ensureCapacity(ArrayList* list, int minCapacity);

array_list_response al_size(ArrayList* list, int* size);

array_list_response al_clear(ArrayList* list);

#endif /* GENERICARRAYLIST_H */


