/* 
 * Author: Manuel Kollmann
 * 
 * This file is under the MIT License
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../genericArrayList.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

static ArrayList* createDemoArrayList() {
    ArrayList* list = create_array_list(sizeof (int));

    int data = 1;
    al_add(list, &data);
    data = 2;
    al_add(list, &data);
    data = 3;
    al_add(list, &data);
    data = 4;
    al_add(list, &data);

    return list;
}

void testCreate_array_list() {
    array_list_response response;
    ArrayList* list = create_array_list(sizeof (int));

    CU_ASSERT(sizeof (*list) == sizeof (ArrayList));
    int size = -1;
    response = al_size(list, &size);
    CU_ASSERT(response == ARRAY_LIST_ok);
}

void testDestroy_array_list() {
    ArrayList* list = createDemoArrayList();
    array_list_response response;

    al_destroy(list);

    //    CU_ASSERT(response == LIST_ok);
    //    CU_ASSERT(list == NULL);
}

void testGet() {
    ArrayList* list = createDemoArrayList();
    array_list_response response;

    int returnElement = -1;
    int index = 0;
    response = al_get(list, index, &returnElement);

    CU_ASSERT(response == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == 1);

    returnElement = -1;
    index = 1000;
    response = al_get(list, index, &returnElement);

    CU_ASSERT(response == ARRAY_LIST_error);

    index = -1;
    response = al_get(list, index, &returnElement);

    CU_ASSERT(response == ARRAY_LIST_error);
}

void testAdd() {
    ArrayList* list = create_array_list(sizeof (long));
    array_list_response response;

    long data = 2;
    int size = -1;
    response = al_add(list, &data);
    CU_ASSERT(response == ARRAY_LIST_ok);
    CU_ASSERT(al_size(list, &size) >= 1);

    data = 10;
    size = -1;
    response = al_add(list, &data);
    CU_ASSERT(response == ARRAY_LIST_ok);
    CU_ASSERT(al_size(list, &size) >= 2);
}

void testSet() {
    ArrayList* list = createDemoArrayList();
    array_list_response response;

    int data = 42;
    int index = 0;
    response = al_set(list, &data, index);
    CU_ASSERT(response == ARRAY_LIST_ok);
    int returnElement = -1;
    response = al_get(list, index, &returnElement);
    CU_ASSERT(response == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == data);
}

void testRemove() {
    ArrayList* list = createDemoArrayList();
    array_list_response response;

    int data = 2;
    response = al_remove(list, &data);
    CU_ASSERT(response == ARRAY_LIST_ok);
    int returnElement = -1;
    CU_ASSERT(al_get(list, 0, &returnElement) == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == 1);
    CU_ASSERT(al_get(list, 0, &returnElement) == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == 3);
    CU_ASSERT(al_get(list, 0, &returnElement) == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == 4);
}

void testRemoveAt() {
    ArrayList* list = createDemoArrayList();
    array_list_response response;

    int removeIndex = 2;
    response = al_remove(list, &removeIndex);
    CU_ASSERT(response == ARRAY_LIST_ok);
    int returnElement = -1;
    CU_ASSERT(al_get(list, 0, &returnElement) == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == 1);
    CU_ASSERT(al_get(list, 0, &returnElement) == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == 2);
    CU_ASSERT(al_get(list, 0, &returnElement) == ARRAY_LIST_ok);
    CU_ASSERT(returnElement == 4);
}

void testContains() {
    ArrayList* list = createDemoArrayList();
    array_list_response response;

    int data = 2;
    bool doesContain;
    response = al_contains(list, &data, &doesContain);
    CU_ASSERT(response == ARRAY_LIST_ok);
    CU_ASSERT(doesContain == true);

    data = -1;
    doesContain;
    response = al_contains(list, &data, &doesContain);
    CU_ASSERT(response == ARRAY_LIST_ok);
    CU_ASSERT(doesContain == false);
}

void testEnsureCapacity() {

}

void testSize() {

}

void testClear() {

}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("cunit_generic-array-list", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreate_array_list", testCreate_array_list)) ||
            (NULL == CU_add_test(pSuite, "testDestroy_array_list", testDestroy_array_list)) ||
            (NULL == CU_add_test(pSuite, "testGet", testGet)) ||
            (NULL == CU_add_test(pSuite, "testAdd", testAdd)) ||
            (NULL == CU_add_test(pSuite, "testSet", testSet)) ||
            (NULL == CU_add_test(pSuite, "testRemove", testRemove)) ||
            (NULL == CU_add_test(pSuite, "testRemove0", testRemoveAt)) ||
            (NULL == CU_add_test(pSuite, "testContains", testContains)) ||
            (NULL == CU_add_test(pSuite, "testEnsureCapacity", testEnsureCapacity)) ||
            (NULL == CU_add_test(pSuite, "testSize", testSize)) ||
            (NULL == CU_add_test(pSuite, "testClear", testClear))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
