/*
 * File:   cunit_map.c
 * Author: kollmanm16
 *
 * Created on 27-Apr-2018, 14:13:19
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <stdbool.h>
#include "../genericMap.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testCreate_map() {
    int numElements;
    int keyTypeSize = sizeof (int);
    int dataTypeSize = sizeof (int);
    Map* result = create_map(numElements, keyTypeSize, dataTypeSize);
    CU_ASSERT_FALSE(result == NULL);
    CU_ASSERT(sizeof (*result) == sizeof (Map));
}

void testCreate_mapelement() {
    char key = 'k';
    int data = 42;
    MapElement* element = create_mapelement_without_map(&key, sizeof (key), &data, sizeof (data));
    CU_ASSERT_FALSE(element == NULL);
    CU_ASSERT(sizeof (*element) == sizeof (MapElement));
}

void testPutElement() {
    // char - int
    Map* map = create_map(10, sizeof (char), sizeof (int));
    char key = 'k';
    int data = 42;
    MapElement* element = create_mapelement(map, &key, &data);
    map_error_code result = map_put_element(map, element);
    CU_ASSERT(result == MAP_ok);
    int size = -1;
    CU_ASSERT(map_size(map, &size) == MAP_ok);
    CU_ASSERT(size == 1);

    // string - float
    const char* key2 = "test";
    float value2 = 12.5;
    Map* map2 = create_map(10, sizeof (key2), sizeof (value2));
    result = map_put(map, key2, &value2);
    CU_ASSERT(result == MAP_ok);
    size = -1;
    CU_ASSERT(map_size(map, &size) == MAP_ok);
    CU_ASSERT(size == 1);
}

void testPutValues() {
    Map* map = create_map(10, sizeof (char), sizeof (int));
    char key = 'k';
    int value = 42;
    map_error_code result = map_put(map, &key, &value);

    CU_ASSERT(result == MAP_ok);
    int size = -1;
    CU_ASSERT(map_size(map, &size) == MAP_ok);
    CU_ASSERT(size == 1);
}

void testGetElement() {
    Map* map = create_map(10, sizeof (char), sizeof (int));

    // first push
    char key = 'k';
    int value = 42;
    map_error_code result = map_put(map, &key, &value);
    CU_ASSERT(result == MAP_ok);

    char key2 = 'x';
    int value2 = 21;
    result = map_put(map, &key2, &value2);
    CU_ASSERT(result == MAP_ok);

    char key3 = 'y';
    int value3 = 12;
    result = map_put(map, &key3, &value3);
    CU_ASSERT(result == MAP_ok);

    // now assert
    MapElement* returnedElement = create_mapelement(map, &key, &value); // init with dummy data
    result = map_get_element(map, &key, returnedElement);
    CU_ASSERT(result == MAP_ok);
    int size = -1;
    CU_ASSERT(map_size(map, &size) == MAP_ok);
    CU_ASSERT(size == 3);
    char* resultKey = returnedElement->key;
    CU_ASSERT(*resultKey == key);
    int* resultValue = returnedElement->value;
    CU_ASSERT(*resultValue == value);
}

void testGetValue() {
    Map* map = create_map(10, sizeof (char), sizeof (int));

    // first push
    char key = 'k';
    int value = 42;
    map_error_code result = map_put(map, &key, &value);
    CU_ASSERT(result == MAP_ok);

    // now assert
    int returnedValue = -1;
    result = map_get(map, &key, &returnedValue);
    CU_ASSERT(result == MAP_ok);
    int size = -1;
    CU_ASSERT(map_size(map, &size) == MAP_ok);
    CU_ASSERT(size == 1);
    CU_ASSERT(returnedValue == value);
}

void testContains_key() {
    Map* map = create_map(10, sizeof (char), sizeof (int));

    // first push
    char key = 'k';
    int value = 42;
    map_error_code result = map_put(map, &key, &value);
    CU_ASSERT(result == MAP_ok);

    // now assert
    bool returnedValue = NULL;
    char notInMap = 'a';
    CU_ASSERT(map_contains_key(map, &key, &returnedValue) == MAP_ok);
    CU_ASSERT(returnedValue == true);
    CU_ASSERT(map_contains_key(map, &notInMap, &returnedValue) == MAP_ok);
    CU_ASSERT(returnedValue == false);
}

void testContains_value() {
    Map* map = create_map(10, sizeof (char), sizeof (int));

    // first push
    char key = 'k';
    int value = 42;
    map_error_code result = map_put(map, &key, &value);
    CU_ASSERT(result == MAP_ok);

    // now assert
    bool returnedValue = NULL;
    result = map_contains_value(map, &value, &returnedValue);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(returnedValue == true);

    int notInMap = 100;
    result = map_contains_value(map, &notInMap, &returnedValue);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(returnedValue == false);
}

void testRemove() {
    Map* map = create_map(10, sizeof (char), sizeof (int));

    // first push
    char key_1 = 'k';
    int value_1 = 42;
    map_error_code result = map_put(map, &key_1, &value_1);
    CU_ASSERT(result == MAP_ok);

    char key_2 = 'a';
    int value_2 = 21;
    result = map_put(map, &key_2, &value_2);
    CU_ASSERT(result == MAP_ok);

    // now assert
    int size = -1;
    result = map_size(map, &size);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(size == 2);

    result = map_remove(map, &key_1);
    size = -1;
    result = map_size(map, &size);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(size == 1);

    // test if the one value still exists and the other not
    bool returnedValue = NULL;
    result = map_contains_key(map, &key_1, &returnedValue);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(returnedValue == true);

    result = map_contains_key(map, &key_2, &returnedValue);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(returnedValue == false);
}

void testClear() {
    Map* map = create_map(10, sizeof (char), sizeof (int));

    // first push
    char key_1 = 'k';
    int value_1 = 42;
    map_error_code result = map_put(map, &key_1, &value_1);
    CU_ASSERT(result == MAP_ok);

    char key_2 = 'a';
    int value_2 = 21;
    result = map_put(map, &key_2, &value_2);
    CU_ASSERT(result == MAP_ok);

    int size = -1;
    result = map_size(map, &size);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(size == 2);

    // now assert
    result = map_clear(map);

    result = map_size(map, &size);
    CU_ASSERT(result == MAP_ok);
    CU_ASSERT(size == 0);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("cunit_map", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreate_map", testCreate_map)) ||
            (NULL == CU_add_test(pSuite, "testCreate_mapelement", testCreate_mapelement)) ||
            (NULL == CU_add_test(pSuite, "testPutElement", testPutElement)) ||
            (NULL == CU_add_test(pSuite, "testPutValues", testPutValues)) ||
            (NULL == CU_add_test(pSuite, "testGetElement", testGetElement)) ||
            (NULL == CU_add_test(pSuite, "testGetValue", testGetValue)) ||
            (NULL == CU_add_test(pSuite, "testContains_key", testContains_key)) ||
            (NULL == CU_add_test(pSuite, "testContains_value", testContains_value)) ||
            (NULL == CU_add_test(pSuite, "testRemove", testRemove)) ||
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
