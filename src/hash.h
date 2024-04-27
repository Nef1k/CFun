#pragma once


#define INITIAL_SIZE 10

typedef char* KEY_T;
typedef char* VALUE_T;
typedef size_t hash_t;


typedef struct kvPair {
	KEY_T key;
	VALUE_T value;
	struct kvPair* next;
} KVPair;

typedef struct hashMap {
	struct kvPair** contents;
	size_t allocated;
	size_t length;
} HashMap;



// Creates an empty hash map of initial size
HashMap* create_hashmap();

// Add KVP to hashmap
void add(HashMap* hashMap, KEY_T key, VALUE_T value);


// Get KVP from hashmap
VALUE_T get(HashMap* hashMap, KEY_T key);


// Destroys given hash map
void destroy_hashmap(HashMap* hashMap);
