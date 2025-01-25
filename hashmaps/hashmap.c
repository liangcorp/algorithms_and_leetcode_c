#include "hashmap.h"

// like constructor
void set_node(struct node *node, char *key, char *value)
{
	node->key = key;
	node->value = value;
	node->next = NULL;
	return;
};

// like constructor
void initialize_hashmap(struct hashMap *mp)
{
	// Default capacity in this case
	mp->capacity = 100;
	mp->numOfElements = 0;

	// array of size = 1
	mp->arr = malloc(mp->capacity * sizeof(struct node *));
	return;
}

int hash_function(struct hashMap *mp, char *key)
{
	int bucketIndex;
	int sum = 0, factor = 31;
	for (int i = 0; i < strlen(key); i++) {
		// sum = sum + (ascii value of
		// char * (primeNumber ^ x))...
		// where x = 1, 2, 3....n
		sum = ((sum % mp->capacity) +
		       (((int)key[i]) * factor) % mp->capacity) %
		      mp->capacity;

		// factor = factor * prime
		// number....(prime
		// number) ^ x
		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) %
			 __INT16_MAX__;
	}

	bucketIndex = sum;
	return bucketIndex;
}

void insert(struct hashMap *mp, char *key, char *value)
{
	// Getting bucket index for the given
	// key - value pair
	int bucketIndex = hash_function(mp, key);
	// Creating a new node
	struct node *newNode = malloc(sizeof(struct node));

	// Setting value of node
	set_node(newNode, key, value);

	// Bucket index is empty....no collision
	if (mp->arr[bucketIndex] == NULL) {
		mp->arr[bucketIndex] = newNode;
	}

	// Collision
	else {
		// Adding newNode at the head of
		// linked list which is present
		// at bucket index....insertion at
		// head in linked list
		newNode->next = mp->arr[bucketIndex];
		mp->arr[bucketIndex] = newNode;
	}
	return;
}

void delete_node(struct hashMap *mp, char *key)
{
	// Getting bucket index for the
	// given key
	int bucketIndex = hash_function(mp, key);

	struct node *prevNode = NULL;

	// Points to the head of
	// linked list present at
	// bucket index
	struct node *currNode = mp->arr[bucketIndex];

	while (currNode != NULL) {
		// Key is matched at delete this
		// node from linked list
		if (strcmp(key, currNode->key) == 0) {
			// Head node
			// deletion
			if (currNode == mp->arr[bucketIndex]) {
				mp->arr[bucketIndex] = currNode->next;
			}

			// Last node or middle node
			else {
				prevNode->next = currNode->next;
			}
			free(currNode);
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	return;
}

char *search(struct hashMap *mp, char *key)
{
	// Getting the bucket index
	// for the given key
	int bucketIndex = hash_function(mp, key);

	// Head of the linked list
	// present at bucket index
	struct node *bucketHead = mp->arr[bucketIndex];
	while (bucketHead != NULL) {
		// Key is found in the hashMap
		if (bucketHead->key == key) {
			return bucketHead->value;
		}
		bucketHead = bucketHead->next;
	}

	// If no key found in the hashMap
	// equal to the given key
	char *errorMssg = malloc(sizeof(char) * 25);
	errorMssg = "Oops! No data found.\n";
	return errorMssg;
}
