#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
	// key is string
	char *key;

	// value is also string
	char *value;
	struct node *next;
};

struct hashMap {
	// Current number of elements in hashMap
	// and capacity of hashMap
	int numOfElements, capacity;

	// hold base address array of linked list
	struct node **arr;
};

void set_node(struct node *node, char *key, char *value);
void initialize_hashmap(struct hashMap *mp);
int hash_function(struct hashMap *mp, char *key);
void insert(struct hashMap *mp, char *key, char *value);
void delete_node(struct hashMap *mp, char *key);
char *search(struct hashMap *mp, char *key);
