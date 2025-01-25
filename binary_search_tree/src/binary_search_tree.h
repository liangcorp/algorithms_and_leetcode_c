// C program to delete
// a node of BST
#include <stdio.h>
#include <stdlib.h>

// Given Node node
struct node {
	int key;
	struct node *left, *right;
};

struct node *new_node(int item);
struct node *insert(struct node *node, int key);
void inorder(struct node *root);
void pre_order(struct node *root);
void post_order(struct node *root);
struct node *min_value_node(struct node *node);
int height(struct node *node);
void print_given_level(struct node *root, int level);
void print_level_order(struct node *root);
void print_leaf_nodes(struct node *root);
void print_none_leaf_node(struct node *root);
void right_view_until(struct node *root, int level, int *max_level);
void right_view(struct node *root);
void left_view_until(struct node *root, int level, int *max_level);
void left_view(struct node *root);
int node_count(struct node *node);
struct node *empty_bst(struct node *root);
struct node *delete_node(struct node *root, int key);
