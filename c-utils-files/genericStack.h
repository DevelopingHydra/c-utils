/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genericStack.h
 * Author: kollmanm16
 *
 * Created on April 24, 2018, 4:01 PM
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

