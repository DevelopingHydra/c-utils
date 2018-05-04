/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genericHashMap.h
 * Author: kollmanm16
 *
 * Created on April 27, 2018, 1:38 PM
 */

#ifndef GENERICHASHMAP_H
#define GENERICHASHMAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

    typedef enum {
        MAP_ok, MAP_error
    } map_error_code;

    typedef struct {
        void* value;
        void* key;
    } MapElement;

    typedef struct {
        int numElements;
        MapElement* elements;
        int indexTop;
        int keyTypeSize;
        int valueTypeSize;
    } Map;

    /**
     * 
     * @param numElements
     * @param keyTypeSize eg. sizeof(char)
     * @param dataTypeSize eg. sizeof(int)
     * @return the created map
     */
    Map* create_map(int numElements, int keyTypeSize, int dataTypeSize);

    MapElement* create_mapelement(Map* map, void* key, void* data);
    MapElement* create_mapelement_without_map(void* key, int keyTypeSize, void* data, int valueTypeSize) ;

    map_error_code map_put_element(Map* map, MapElement* element);
    map_error_code map_put(Map* map, void* key, void* data);

    map_error_code map_get_element(Map* map, void* key, MapElement* returnData);
    map_error_code map_get(Map* map, void* key, void* returnData);

    map_error_code map_contains_key(Map* map, void* key, bool* returnValue);
    map_error_code map_contains_value(Map* map, void* value, bool* returnValue);

    map_error_code map_remove(Map* map, void* key);
    map_error_code map_clear(Map* map);

    map_error_code map_size(Map* map, int* returnValue);


#ifdef __cplusplus
}
#endif

#endif /* GENERICHASHMAP_H */

