/* 
 * Author: Manuel Kollmann
 * 
 * This file is under the MIT License
 */

#ifndef GENERICSTACK_H
#define GENERICSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

    enum {
        STACK_ok,
        STACK_error
    };

    typedef struct {
        void* data;
        int indexTop;
        int totalElements;
        int memberSize;
    } Stack;

    Stack* create_stack(int memberSize, int totalElements);

    int stack_push(Stack* s, void* element);
    int stack_pop(Stack* s, void* target);
    int stack_top(Stack* s, void* target);

    int stack_destroy(Stack* s);


#ifdef __cplusplus
}
#endif

#endif /* GENERICSTACK_H */

