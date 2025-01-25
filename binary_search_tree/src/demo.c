#include "binary_search_tree.h"

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
	root = delete_node(root, 60);
	inorder(root);

    empty_bst(root);
	return 0;
}
