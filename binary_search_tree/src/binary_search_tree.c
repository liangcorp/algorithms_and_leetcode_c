#include "binary_search_tree.h"

// Function to create a new BST node
struct node *new_node(int item)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to insert a new node with
// given key in BST
struct node *insert(struct node *node, int key)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return new_node(key);

	// Otherwise, recur down the tree
	if (key < node->key) {
		node->left = insert(node->left, key);
	} else if (key > node->key) {
		node->right = insert(node->right, key);
	}

	// Return the node pointer
	return node;
}

// Function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

// Function to do pre_order traversal of BST
void pre_order(struct node *root)
{
	if (root != NULL) {
		printf("%d ", root->key);
		pre_order(root->left);
		pre_order(root->right);
	}
}

// Function to do post_order traversal of BST
void post_order(struct node *root)
{
	if (root != NULL) {
		post_order(root->left);
		post_order(root->right);
		printf("%d ", root->key);
	}
}

// Function that returns the node with minimum
// key value found in that tree
struct node *min_value_node(struct node *node)
{
	struct node *current = node;

	// Loop down to find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

// Returns height of the BST
int height(struct node *node)
{
	if (node == NULL)
		return 0;
	else {
		// Compute the depth of each subtree
		int lDepth = height(node->left);
		int rDepth = height(node->right);

		// Use the larger one
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

// Print nodes at a given level
void print_given_level(struct node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->key);
	else if (level > 1) {
		// Recursive Call
		print_given_level(root->left, level - 1);
		print_given_level(root->right, level - 1);
	}
}

// Function to line by line print
// level order traversal a tree
void print_level_order(struct node *root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++) {
		print_given_level(root, i);
		printf("\n");
	}
}

// Function to print leaf nodes
// from left to right
void print_leaf_nodes(struct node *root)
{
	// If node is null, return
	if (!root)
		return;

	// If node is leaf node,
	// print its data
	if (!root->left && !root->right) {
		printf("%d ", root->key);
		return;
	}

	// If left child exists,
	// check for leaf recursively
	if (root->left)
		print_leaf_nodes(root->left);

	// If right child exists,
	// check for leaf recursively
	if (root->right)
		print_leaf_nodes(root->right);
}

// Function to print all non-leaf
// nodes in a tree
void print_none_leaf_node(struct node *root)
{
	// Base Cases
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;

	// If current node is non-leaf,
	if (root->left != NULL || root->right != NULL) {
		printf("%d ", root->key);
	}

	// If root is Not NULL and its one
	// of its child is also not NULL
	print_none_leaf_node(root->left);
	print_none_leaf_node(root->right);
}

// Function to print the right view
// of a binary tree.
void right_view_until(struct node *root, int level, int *max_level)
{
	// Base Case
	if (root == NULL)
		return;

	// If this is the last Node of its level
	if (*max_level < level) {
		printf("%d\t", root->key);
		*max_level = level;
	}

	// Recur for right subtree first,
	// then left subtree
	right_view_until(root->right, level + 1, max_level);

	right_view_until(root->left, level + 1, max_level);
}

// Wrapper over right_view_until()
void right_view(struct node *root)
{
	int max_level = 0;
	right_view_until(root, 1, &max_level);
}

// Function to print left view of
// binary tree
void left_view_until(struct node *root, int level, int *max_level)
{
	// Base Case
	if (root == NULL)
		return;

	// If this is the first node
	// of its level
	if (*max_level < level) {
		printf("%d\t", root->key);
		*max_level = level;
	}

	// Recur for left and right subtrees
	left_view_until(root->left, level + 1, max_level);

	left_view_until(root->right, level + 1, max_level);
}

// Wrapper over left_view_until()
void left_view(struct node *root)
{
	int max_level = 0;
	left_view_until(root, 1, &max_level);
}

// Function to get the total count of
// nodes in a binary tree
int node_count(struct node *node)
{
	if (node == NULL)
		return 0;

	else
		return node_count(node->left) + node_count(node->right) + 1;
}

// Function to delete the BST
struct node *empty_bst(struct node *root)
{
	struct node *temp;
	if (root != NULL) {
		// Traverse to left subtree
		empty_bst(root->left);

		// Traverse to right subtree
		empty_bst(root->right);

		printf("Released node:%d \n", root->key);
		temp = root;

		// Require for free memory
		free(temp);
	}
	return root;
}

// Function that deletes the key and
// returns the new root
struct node *delete_node(struct node *root, int key)
{
	// base Case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}

	// If the key to be deleted is
	// greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}

	// If key is same as root's key,
	// then this is the node
	// to be deleted
	else {
		// Node with only one child
		// or no child
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// Node with two children:
		// Get the inorder successor(smallest
		// in the right subtree)
		struct node *temp = min_value_node(root->right);

		// Copy the inorder successor's
		// content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
