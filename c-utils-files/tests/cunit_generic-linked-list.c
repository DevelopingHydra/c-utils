/* 
 * Author: Manuel Kollmann
 * 
 * This file is under the MIT License
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../genericLinkedList.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

static LinkedListElement* createDummyLinkedList() {
    long data = 1;
    LinkedListElement* list = create_linked_list(sizeof (long), &data);
    for (int i = 0; i < 10; i++) {
        long value = i;
        ll_add(list, &value);
    }

    return list;
}

void testCreate_linked_list() {
    int someData = 42;
    LinkedListElement* createdElement = create_linked_list(sizeof (int), &someData);

    CU_ASSERT(sizeof (*createdElement) == sizeof (LinkedListElement));
}

void testLl_destroy_all() {
    LinkedListElement* list = createDummyLinkedList();
    
    ll_destroy_all(list);
}

void testLl_get() {
    LinkedListElement* list = createDummyLinkedList();

    long data = -1;
    int index = 1;
    linked_list_response respone = ll_get(list, index, &data);

    CU_ASSERT(respone == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(data == 0);
}

void testLl_add() {
    char someData = 'a';
    LinkedListElement* list = create_linked_list(sizeof (char), &someData);

    int size = -1;
    linked_list_response response = ll_size(list, &size);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(size == 1);

    someData = 'b';
    response = ll_add(list, &someData);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);

    size = -1;
    response = ll_size(list, &size);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(size == 2);
}

void testLl_remove() {
    LinkedListElement* list = createDummyLinkedList();

    int size = -1;
    linked_list_response response = ll_size(list, &size);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(size == 11);

    long dataToRemove = 0;
    response = ll_remove(list, &dataToRemove);

    size = -1;
    response = ll_size(list, &size);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(size == 10);

    bool isInList = true;
    response = ll_contains(list, &dataToRemove, &isInList);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(isInList == false);
}

void testLl_remove_at() {
    LinkedListElement* list = createDummyLinkedList();

    int size = -1;
    linked_list_response response = ll_size(list, &size);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(size == 11);

    // get second element
    long secondElement = -1;
    int index = 1;
    CU_ASSERT(ll_get(list, index, &secondElement) == LINKED_LIST_RESPONSE_ok);

    // now remove it
    CU_ASSERT(ll_remove_at(list, index) == LINKED_LIST_RESPONSE_ok);

    // now check the second element again
    long newSecondElement = -1;
    CU_ASSERT(ll_get(list, index, &newSecondElement) == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(secondElement != newSecondElement);

    // also check size
    size = -1;
    response = ll_size(list, &size);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(size == 10);
}

void testLl_contains() {
    LinkedListElement* list = createDummyLinkedList();

    bool isInList = false;
    long data = 9;
    linked_list_response response = ll_contains(list, &data, &isInList);
    CU_ASSERT(response == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(isInList == true);

    data = 100;
    CU_ASSERT(ll_contains(list, &data, &isInList) == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(isInList == false);
}

void testLl_size() {
    LinkedListElement* list = createDummyLinkedList();

    int size = -1;
    CU_ASSERT(ll_size(list, &size) == LINKED_LIST_RESPONSE_ok);
    CU_ASSERT(size == 11);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("cunit_linked-list", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreate_linked_list", testCreate_linked_list)) ||
            (NULL == CU_add_test(pSuite, "testLl_destroy_all", testLl_destroy_all)) ||
            (NULL == CU_add_test(pSuite, "testLl_get", testLl_get)) ||
            (NULL == CU_add_test(pSuite, "testLl_add", testLl_add)) ||
            (NULL == CU_add_test(pSuite, "testLl_remove", testLl_remove)) ||
            (NULL == CU_add_test(pSuite, "testLl_remove_at", testLl_remove_at)) ||
            (NULL == CU_add_test(pSuite, "testLl_contains", testLl_contains)) ||
            (NULL == CU_add_test(pSuite, "testLl_size", testLl_size))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
