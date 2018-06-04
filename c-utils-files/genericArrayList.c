/* 
 * Author: Manuel Kollmann
 * 
 * This file is under the MIT License
 */

#include <string.h>

#include "genericArrayList.h"

ArrayList* create_array_list(int dataTypeSize) {
    ArrayList* list = malloc(sizeof (ArrayList));

    list->size = 1;
    list->dataTypeSize = dataTypeSize;
    list->array = calloc(list->size, list->dataTypeSize);

    return list;
}

void al_destroy(ArrayList* list) {
    free(list->array);
    free(list);
}

array_list_response al_get(ArrayList* list, int index, void* returnElement) {
    if (index > list->size) {
        return ARRAY_LIST_error;
    }

    char* pointerToArrayStart = (char*) list->array;
    pointerToArrayStart += index * list->dataTypeSize;

    memcpy(returnElement, pointerToArrayStart, list->dataTypeSize);

    return ARRAY_LIST_ok;
}

array_list_response al_add(ArrayList* list, void* data) {
    if (list->indexTop == list->size) {
        array_list_response response = al_ensureCapacity(list, list->size * 2);
        if (response == ARRAY_LIST_error) {
            return ARRAY_LIST_error;
        }
    }

    list->indexTop++;
    char* pointerToArray = (char*) list->array;
    pointerToArray += list->indexTop * list->dataTypeSize;

    memcpy(pointerToArray, data, list->dataTypeSize);

    return ARRAY_LIST_ok;
}

array_list_response al_set(ArrayList* list, void* data, int index) {
    if (index > list->size) {
        return ARRAY_LIST_error;
    }

    char* pointerToArray = (char*) list->array;
    pointerToArray += index * list->dataTypeSize;

    memcpy(pointerToArray, data, list->dataTypeSize);

    return ARRAY_LIST_ok;
}

array_list_response al_remove(ArrayList* list, void* data) {

}

array_list_response al_remove_at(ArrayList* list, int index) {
    if (index > list->size) {
        return ARRAY_LIST_error;
    }

    char* pointerToArray = (char*) list->array;
    pointerToArray += index * list->dataTypeSize;

    memset(pointerToArray, 0, list->dataTypeSize);

    return ARRAY_LIST_ok;
}

array_list_response al_contains(ArrayList* list, void* data, bool* result) {
    for (int i = 0; i < list->size; i++) {
        void* currData = calloc(1, list->dataTypeSize);
        al_get(list, i, &currData);
        if (memcmp(data, currData, list->dataTypeSize) == 0) {
            *result = true;
            return ARRAY_LIST_ok;
        }
    }
    *result = false;
    return ARRAY_LIST_ok;
}

array_list_response al_ensureCapacity(ArrayList* list, int minCapacity) {
    list->array = realloc(list->array, minCapacity * list->dataTypeSize);

    return ARRAY_LIST_ok;
}

array_list_response al_size(ArrayList* list, int* size) {
    *size = list->size;

    return ARRAY_LIST_ok;
}

array_list_response al_clear(ArrayList* list) {
    memset(list->array, 0, list->dataTypeSize);

    return ARRAY_LIST_ok;
}
