#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "genericMap.h"

static MapElement* init_empty_mapelement(int keyTypeSize, int valueTypeSize);

Map* create_map(int numElements, int keyTypeSize, int dataTypeSize) {
    Map* map = malloc(sizeof (Map));

    map->numElements = numElements;
    map->indexTop = 0;
    map->keyTypeSize = keyTypeSize;
    map->valueTypeSize = dataTypeSize;
    map->elements = calloc(numElements, sizeof (MapElement));

    return map;
}

static MapElement* init_empty_mapelement(int keyTypeSize, int valueTypeSize) {
    MapElement* mapElement = malloc(sizeof (MapElement));

    mapElement->key = calloc(1, keyTypeSize);
    mapElement->value = calloc(1, valueTypeSize);

    return mapElement;
}

MapElement* create_mapelement_without_map(void* key, int keyTypeSize, void* value, int valueTypeSize) {
    MapElement* mapElement = init_empty_mapelement(keyTypeSize, valueTypeSize);

    memcpy(mapElement->key, key, sizeof (keyTypeSize));
    memcpy(mapElement->value, value, sizeof (valueTypeSize));

    return mapElement;
}

MapElement* create_mapelement(Map* map, void* key, void* value) {
    return create_mapelement_without_map(key, map->keyTypeSize, value, map->valueTypeSize);
}

map_error_code map_put_element(Map* map, MapElement* element) {
    if (map->indexTop >= map->numElements) {
        return MAP_error;
    }

    void* target = map->elements + map->indexTop;
    memcpy(target, element, sizeof (MapElement));
    map->indexTop++;

    return MAP_ok;
}

map_error_code map_put(Map* map, void* key, void* data) {
    MapElement* newElement = create_mapelement(map, key, data);
    return map_put_element(map, newElement);
}

map_error_code map_get_element(Map* map, void* key, MapElement* returnElement) {
    for (int i = 0; i < map->indexTop; i++) {
        MapElement* currElement = map->elements + i;
        if (sizeof (key) == sizeof (map->keyTypeSize)) {
            if (memcmp(key, currElement->key, sizeof (*key)) == 0) {
                // found
                returnElement->key = currElement->key;
                returnElement->value = currElement->value;

                return MAP_ok;
            }
        }
    }
    return MAP_error;
}

map_error_code map_get(Map* map, void* key, void* returnData) {

    MapElement* foundElement = init_empty_mapelement(map->keyTypeSize, map->valueTypeSize);
    map_error_code errorCode = map_get_element(map, key, foundElement);
    if (errorCode != MAP_ok) {
        return errorCode;
    }

    memcpy(returnData, foundElement->value, sizeof (map->valueTypeSize));

    return MAP_ok;
}

map_error_code map_contains_key(Map* map, void* key, bool* returnValue) {
    MapElement* foundElement = init_empty_mapelement(map->keyTypeSize, map->valueTypeSize);
    map_error_code errorCode = map_get_element(map, key, foundElement);
    *returnValue = errorCode == MAP_ok;
    return MAP_ok;
}

/**
 * todo implement
 * @param map
 * @param value
 * @param returnValue
 * @return 
 */
map_error_code map_contains_value(Map* map, void* value, bool* returnValue) {
    for (int i = 0; i < map->indexTop; i++) {
        MapElement* currElement = map->elements + i;
        if (sizeof (value) == sizeof (map->valueTypeSize)) {
            if (memcmp(value, currElement->value, sizeof (*value)) == 0) {
                // found
                *returnValue = true;

                return MAP_ok;
            }
        }
    }
    *returnValue = false;
    return MAP_ok;
}

/**
 * todo implement
 * @param map
 * @param key
 * @return 
 */
map_error_code map_remove(Map* map, void* key) {
    return MAP_error;
}

/**
 * todo make it clean everything (void pointers inside element are not freed)
 * @param map
 * @return 
 */
map_error_code map_clear(Map* map) {
    MapElement* currElement = NULL;
    for (int i = 0; i < map->indexTop; i++) {
        currElement = map->elements + i;
        // clear pointer of element
        // not working
        //        free(currElement->key);
        //        free(currElement->value);
        // clear whole element
//        free(currElement);
    }
    map->indexTop = 0;
    return MAP_ok;
}

map_error_code map_size(Map* map, int* returnValue) {
    int size = map->indexTop;
    *returnValue = size;
    return MAP_ok;
}