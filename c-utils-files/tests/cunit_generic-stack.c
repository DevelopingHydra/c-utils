/*
 * File:   newcunittest.c
 * Author: xeniu
 *
 * Created on 04.05.2018, 22:18:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../genericStack.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testCreate_stack() {
    int memberSize;
    int totalElements;
    Stack* result = create_stack(memberSize, totalElements);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testStack_push() {
    Stack* s;
    void* element;
    int result = stack_push(s, element);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testStack_pop() {
    Stack* s;
    void* target;
    int result = stack_pop(s, target);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testStack_top() {
    Stack* s;
    void* target;
    int result = stack_top(s, target);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testStack_destroy() {
    Stack* s;
    int result = stack_destroy(s);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreate_stack", testCreate_stack)) ||
            (NULL == CU_add_test(pSuite, "testStack_push", testStack_push)) ||
            (NULL == CU_add_test(pSuite, "testStack_pop", testStack_pop)) ||
            (NULL == CU_add_test(pSuite, "testStack_top", testStack_top)) ||
            (NULL == CU_add_test(pSuite, "testStack_destroy", testStack_destroy))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
