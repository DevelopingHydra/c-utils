/* 
 * Author: Manuel Kollmann
 * 
 * This file is under the MIT License
 */

#include <string.h>

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "genericLinkedList.h"

static LinkedListElement* getElementAt(LinkedListElement* list, int index);
static LinkedListElement* getElementByData(LinkedListElement* list, void* data);
static void freeElement(LinkedListElement* element);
static void removeElement(LinkedListElement* elementToRemove);

LinkedListElement* create_linked_list(int dataTypeSize, void* data) {
    LinkedListElement* newElement = calloc(1, sizeof (LinkedListElement));

    newElement->dataTypeSize = dataTypeSize;
    newElement->beforeElement = NULL;
    newElement->nextElement = NULL;

    newElement->data = calloc(1, dataTypeSize);
    memcpy(newElement->data, data, sizeof (dataTypeSize));

    return newElement;
}

void ll_destroy_all(LinkedListElement* list) {
    int tmp = -1;
    LinkedListElement* currElement = getHead(list, &tmp);

    while (currElement->nextElement != NULL) {
        LinkedListElement* tmp = currElement;
        currElement = currElement->nextElement;
        freeElement(tmp);
    }
}

linked_list_response ll_get(LinkedListElement* list, int index, void* returnElement) {
    LinkedListElement* targetElement = getElementAt(list, index);
    memcpy(returnElement, targetElement->data, sizeof (targetElement->dataTypeSize));

    return LINKED_LIST_RESPONSE_ok;
}

linked_list_response ll_add(LinkedListElement* list, void* data) {
    LinkedListElement* newElement = create_linked_list(list->dataTypeSize, data);
    int tmp = 0;
    LinkedListElement* tail = getTail(list, &tmp);

    tail->nextElement = newElement;
    newElement->beforeElement = tail;

    return LINKED_LIST_RESPONSE_ok;
}

linked_list_response ll_remove(LinkedListElement* list, void* data) {
    LinkedListElement* elementToRemove = getElementByData(list, data);
    if (elementToRemove != NULL) {
        removeElement(elementToRemove);

        return LINKED_LIST_RESPONSE_ok;
    } else {
        return LINKED_LIST_RESPONSE_error;
    }
}

linked_list_response ll_remove_at(LinkedListElement* list, int index) {
    LinkedListElement* elementToRemove = getElementAt(list, index);
    if (elementToRemove != NULL) {
        removeElement(elementToRemove);

        return LINKED_LIST_RESPONSE_ok;
    } else {
        return LINKED_LIST_RESPONSE_error;
    }
}

linked_list_response ll_contains(LinkedListElement* list, void* data, bool* result) {
    LinkedListElement* foudnElement = getElementByData(list, data);
    if (foudnElement != NULL) {
        *result = true;
        return LINKED_LIST_RESPONSE_ok;
    } else {
        *result = false;
        return LINKED_LIST_RESPONSE_ok;
    }
}

linked_list_response ll_size(LinkedListElement* list, int* size) {
    int numElementsTillHead = -1;
    getHead(list, &numElementsTillHead);

    int numElementsTillTail = -1;
    getTail(list, &numElementsTillTail);

    *size = numElementsTillHead + numElementsTillTail + 1;

    return LINKED_LIST_RESPONSE_ok;
}

LinkedListElement* getHead(LinkedListElement* list, int* traversedElements) {
    LinkedListElement* currHead = list;
    int count = 0;
    while (currHead->beforeElement) {
        currHead = currHead->beforeElement;
        count++;
    }
    *traversedElements = count;
    return currHead;
}

LinkedListElement* getTail(LinkedListElement* list, int* travesedElements) {
    LinkedListElement* currHead = list;
    *travesedElements = 0;
    while (currHead->nextElement) {
        currHead = currHead->nextElement;
        *travesedElements += 1;
    }
    return currHead;
}

static LinkedListElement* getElementAt(LinkedListElement* list, int index) {
    int numElementsTillHead = -1;
    LinkedListElement* head = getHead(list, &numElementsTillHead);
    LinkedListElement* currElement = head;

    for (int i = 0; i < index; i++) {
        if (currElement->nextElement != NULL) {
            currElement = currElement->nextElement;
        } else {
            printf("ERROR ERROR ERROR");
            return NULL;
        }
    }

    return currElement;
}

static LinkedListElement* getElementByData(LinkedListElement* list, void* data) {
    int tmp;
    LinkedListElement* head = getHead(list, &tmp);
    LinkedListElement* currElement = head;

    while (currElement != NULL) {
        if (memcmp(data, currElement->data, sizeof (currElement->dataTypeSize)) == 0) {
            return currElement;
        } else {
            currElement = currElement->nextElement;
        }
    }

    return NULL;
}

static void freeElement(LinkedListElement* element) {
    free(element->data);
    free(element);
}

static void removeElement(LinkedListElement* elementToRemove) {
    LinkedListElement* before = elementToRemove->beforeElement;
    LinkedListElement* next = elementToRemove->nextElement;

    freeElement(elementToRemove);

    if (before != NULL) {
        before->nextElement = next;
    }
    if (next != NULL) {
        next->beforeElement = before;
    }
}