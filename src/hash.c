#include <stdlib.h>
#include <string.h>
#include "hash.h"


long int _calc_key(KEY_T key) {
    return strlen(key);
}

hash_t _hash(HashMap* hashMap, KEY_T key) {
    return _calc_key(key) % hashMap->allocated;
}



HashMap* create_hashmap() {
    HashMap* newHashMap = (HashMap*) malloc(sizeof(HashMap));


    newHashMap->contents = (struct kvPair**) malloc(
        INITIAL_SIZE * sizeof(KVPair)
    );
    newHashMap->allocated = INITIAL_SIZE;
    newHashMap->length = 0;

    for (size_t i = 0; i < newHashMap->allocated; i++) {
        newHashMap->contents[i] = NULL;
    }

    return newHashMap;
}


void add(HashMap* hashMap, KEY_T key, VALUE_T value) {
    struct kvPair* newPair = (struct kvPair*) malloc(sizeof(KVPair));
    newPair->key = key;
    newPair->value = value;
    newPair->next = NULL;

    hash_t hash = _hash(hashMap, key);

    if (hashMap->contents[hash] == NULL) {
        hashMap->contents[hash] = newPair;
    } else {
        // Get first element
        struct kvPair* firstElement = hashMap->contents[hash];
        // Remember existing element
        newPair->next = firstElement;
        // Set new element as head
        hashMap->contents[hash] = newPair;
    }
}

VALUE_T get(HashMap* hashMap, KEY_T key) {
    hash_t hash = _hash(hashMap, key);
    struct kvPair* foundPair = hashMap->contents[hash];

    if (foundPair == NULL) {
        return "404 NOT FOUND";
    }

    if (foundPair->key == key) {
        return foundPair->value;
    } else {
        while (foundPair != NULL) {
            if (foundPair->key == key) {
                return foundPair->value;
            }

            foundPair = foundPair->next;
        }
    }

    return "404 NOT FOUND";
}


void destroy_hashmap(HashMap* hashMap) {
    // TODO: free all the allocated memory and noy only shell of it
    // for (size_t i = 0; i < hashMap->allocated; i++) {
    //     KVPair* current = hashMap->contents[i];
    //     while (current != NULL) {
    //         KVPair* next = current->next;
    //         free(current);
    //         current = next;
    //     }
    // }
    free(hashMap->contents);
    free(hashMap);
}
