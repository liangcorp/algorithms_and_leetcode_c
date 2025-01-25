#include "hashmap.h"

// like constructor
void set_node(struct Node *node, char *key, char *value)
{
	node->key = key;
	node->value = value;
	node->next = NULL;
	return;
};

// like constructor
void initialize_hashmap(struct HashMap *mp)
{
	// Default capacity in this case
	mp->capacity = CAPACITY;
	mp->num_of_elements = 0;

	// array of size = 1
	mp->arr = malloc(mp->capacity * sizeof(struct node *));
	return;
}

int hash_function(struct HashMap *mp, char *key)
{
	int bucket_index;
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

	bucket_index = sum;
	return bucket_index;
}

void insert(struct HashMap *mp, char *key, char *value)
{
	// Getting bucket index for the given
	// key - value pair
	int bucket_index = hash_function(mp, key);
	// Creating a new node
	struct Node *new_node = malloc(sizeof(struct Node));

	// Setting value of node
	set_node(new_node, key, value);

	// Bucket index is empty....no collision
	if (mp->arr[bucket_index] == NULL) {
		mp->arr[bucket_index] = new_node;
	}

	// Collision
	else {
		// Adding new_node at the head of
		// linked list which is present
		// at bucket index....insertion at
		// head in linked list
		new_node->next = mp->arr[bucket_index];
		mp->arr[bucket_index] = new_node;
	}
	return;
}

void delete_node(struct HashMap *mp, char *key)
{
	// Getting bucket index for the
	// given key
	int bucket_index = hash_function(mp, key);

	struct Node *prev_node = NULL;

	// Points to the head of
	// linked list present at
	// bucket index
	struct Node *current_node = mp->arr[bucket_index];

	while (current_node != NULL) {
		// Key is matched at delete this
		// node from linked list
		if (strcmp(key, current_node->key) == 0) {
			// Head node
			// deletion
			if (current_node == mp->arr[bucket_index]) {
				mp->arr[bucket_index] = current_node->next;
			}

			// Last node or middle node
			else {
				prev_node->next = current_node->next;
			}
			free(current_node);
			break;
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
	return;
}

char *search(struct HashMap *mp, char *key)
{
	// Getting the bucket index
	// for the given key
	int bucket_index = hash_function(mp, key);

	// Head of the linked list
	// present at bucket index
	struct Node *bucket_head = mp->arr[bucket_index];
	while (bucket_head != NULL) {
		// Key is found in the hashMap
		if (bucket_head->key == key) {
			return bucket_head->value;
		}
		bucket_head = bucket_head->next;
	}

	// If no key found in the hashMap
	// equal to the given key
	char *error_msg = malloc(sizeof(char) * 25);
	error_msg = "Oops! No data found.\n";
	return error_msg;
}
