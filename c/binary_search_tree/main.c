// C program to delete
// a node of BST
#include <stdio.h>
#include <stdlib.h>

// Given Node node
struct node {
	int key;
	struct node *left, *right;
};

// Function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
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
		return newNode(key);

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

// Function to do preorder traversal of BST
void preOrder(struct node *root)
{
	if (root != NULL) {
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// Function to do postorder traversal of BST
void postOrder(struct node *root)
{
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
}

// Function that returns the node with minimum
// key value found in that tree
struct node *minValueNode(struct node *node)
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
void printGivenLevel(struct node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->key);
	else if (level > 1) {
		// Recursive Call
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

// Function to line by line print
// level order traversal a tree
void printLevelOrder(struct node *root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++) {
		printGivenLevel(root, i);
		printf("\n");
	}
}

// Function to print leaf nodes
// from left to right
void printLeafNodes(struct node *root)
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
		printLeafNodes(root->left);

	// If right child exists,
	// check for leaf recursively
	if (root->right)
		printLeafNodes(root->right);
}

// Function to print all non-leaf
// nodes in a tree
void printNonLeafNode(struct node *root)
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
	printNonLeafNode(root->left);
	printNonLeafNode(root->right);
}

// Function to print the right view
// of a binary tree.
void rightViewUtil(struct node *root, int level, int *max_level)
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
	rightViewUtil(root->right, level + 1, max_level);

	rightViewUtil(root->left, level + 1, max_level);
}

// Wrapper over rightViewUtil()
void rightView(struct node *root)
{
	int max_level = 0;
	rightViewUtil(root, 1, &max_level);
}

// Function to print left view of
// binary tree
void leftViewUtil(struct node *root, int level, int *max_level)
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
	leftViewUtil(root->left, level + 1, max_level);

	leftViewUtil(root->right, level + 1, max_level);
}

// Wrapper over leftViewUtil()
void leftView(struct node *root)
{
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

// Function to get the total count of
// nodes in a binary tree
int nodeCount(struct node *node)
{
	if (node == NULL)
		return 0;

	else
		return nodeCount(node->left) + nodeCount(node->right) + 1;
}

// Function to delete the BST
struct node *emptyBST(struct node *root)
{
	struct node *temp;
	if (root != NULL) {
		// Traverse to left subtree
		emptyBST(root->left);

		// Traverse to right subtree
		emptyBST(root->right);

		printf("Released node:%d \n", root->key);
		temp = root;

		// Require for free memory
		free(temp);
	}
	return root;
}

// Function that deletes the key and
// returns the new root
struct node *deleteNode(struct node *root, int key)
{
	// base Case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}

	// If the key to be deleted is
	// greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
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
		struct node *temp = minValueNode(root->right);

		// Copy the inorder successor's
		// content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// Driver Code
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80
*/
	struct node *root = NULL;

	// Creating the BST
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// Function Call
	root = deleteNode(root, 60);
	inorder(root);

	return 0;
}
