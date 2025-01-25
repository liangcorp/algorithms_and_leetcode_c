#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

// Linked List node
struct Node {
	// key is string
	char *key;

	// value is also string
	char *value;
	struct Node *next;
};

struct HashMap {
	// Current number of elements in HashMap
	// and capacity of HashMap
	int num_of_elements, capacity;

	// hold base address array of linked list
	struct Node **arr;
};

void set_node(struct Node *Node, char *key, char *value);
void initialize_hashmap(struct HashMap *mp);
int hash_function(struct HashMap *mp, char *key);
void insert(struct HashMap *mp, char *key, char *value);
void delete_node(struct HashMap *mp, char *key);
char *search(struct HashMap *mp, char *key);
