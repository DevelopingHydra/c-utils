/* 
 * Author: Manuel Kollmann
 * 
 * This file is under the MIT License
 */

#include <stdlib.h>
#include <memory.h>
#include "genericStack.h"

/**
 * Creates a stack struct which can hold elements with the type specified<br>
 * This stack gets bigger automatically if it's too small
 * @param memberSize e.g. sizeof(int)
 * @param totalElements first batch of elements
 * @return 
 */
Stack* create_stack(int memberSize, int totalElements) {
    Stack* s = malloc(sizeof (Stack));
    s->indexTop = -1;
    s->memberSize = memberSize;
    s->totalElements = totalElements;
    s->data = malloc(totalElements * memberSize);
    return s;
}

int expand_stack(Stack* s) {
    s->data = realloc(s->data, s->totalElements * 2);
    s->totalElements *= 2;
    return STACK_ok;
}

int stack_push(Stack* s, void* element) {
    // check if stack is full
    if (s->indexTop == s->totalElements - 1) {
        expand_stack(s);
    }

    s->indexTop++;
    void* target = (char*) s->data + (s->indexTop * s->memberSize);
    memcpy(target, element, s->memberSize);
    return STACK_ok;
}

int stack_pop(Stack*s, void* target) {
    if (s->indexTop == -1) {
        return STACK_error;
    }
    stack_top(s, target);
    s->indexTop--;
    return STACK_ok;
}

/**
 * 
 * @param s
 * @param target
 * @return the top element without removing it
 */
int stack_top(Stack* s, void* target) {
    if (s->indexTop == -1) {
        return STACK_error;
    }

    void* source = (char*) s->data + (s->indexTop * s->memberSize);
    memcpy(target, source, s->memberSize);
    return STACK_ok;
}

int stack_destroy(Stack* s) {
    free(s->data);
    free(s);
    return STACK_ok;
}