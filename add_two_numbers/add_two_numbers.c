#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void add_last(struct ListNode *head, int val)
{
	struct ListNode *new_node = NULL;
	new_node = calloc(1, sizeof(struct ListNode));
	new_node->val = val;
	new_node->next = NULL;

	while (head->next != NULL) {
		head = head->next;
	}
	head->next = new_node;
}

void display(struct ListNode *head)
{
	struct ListNode *c_node = head;

	while (c_node != NULL) {
		printf("%d\n", c_node->val);
		if (c_node->next == NULL)
			break;

		c_node = c_node->next;
	}
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *result = calloc(1, sizeof(struct ListNode));
	struct ListNode *head = result;

	int carry_over = 0;
	int left_over = 0;

	while (l1 != NULL || l2 != NULL || carry_over == 1) {
		if (l1 == NULL && l2 != NULL) {
			left_over = l2->val + carry_over;
			l2 = l2->next;
		} else if (l1 != NULL && l2 == NULL) {
			left_over = l1->val + carry_over;
			l1 = l1->next;
		} else if (l1 == NULL && l2 == NULL && carry_over == 1) {
			left_over = carry_over;
			carry_over = 0;
		} else {
			left_over = l1->val + l2->val + carry_over;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (left_over > 9) {
			left_over %= 10;
			carry_over = 1;
		} else {
			carry_over = 0;
		}

		result->val = left_over;
		if (l1 != NULL || l2 != NULL || carry_over == 1) {
			result->next = calloc(1, sizeof(struct ListNode));
			result = result->next;
		}
	}

	return head;
}

// Does the same thing. No obvious speed improvment
struct ListNode *addTwoNumbers2(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *result = calloc(1, sizeof(struct ListNode));
	struct ListNode *head = result;

	int carry_over = 0;
	int left_over = 0;

	while (1 == 1) {
		int l1_val = (l1 != NULL) ? l1->val : 0;
		int l2_val = (l2 != NULL) ? l2->val : 0;

		int sum = l1_val + l2_val + carry_over;

		carry_over = sum / 10;
		result->val = sum % 10;

		if (l1 != NULL)
			l1 = l1->next;

		if (l2 != NULL)
			l2 = l2->next;

		if (l1 == NULL && l2 == NULL && carry_over == 0)
			return head;

		result->next = calloc(1, sizeof(struct ListNode));
		result = result->next;
	}
}

void free_list(struct ListNode *head)
{
	struct ListNode *n_remove = NULL;

	while (n_remove != NULL) {
		n_remove = head;
		head = head->next;
		free(n_remove);
	}
}

int main()
{
	struct ListNode *l1 = NULL;
	struct ListNode *l2 = NULL;

	l1 = calloc(1, sizeof(struct ListNode));
	l1->val = 9;
	add_last(l1, 9);
	add_last(l1, 9);
	add_last(l1, 9);
	add_last(l1, 9);
	add_last(l1, 9);
	add_last(l1, 9);

	l2 = calloc(1, sizeof(struct ListNode));
	l2->val = 9;
	add_last(l2, 9);
	add_last(l2, 9);
	add_last(l2, 9);

	// printf("print nodes\n");
	// display(l1);
	// display(l2);

	struct ListNode *result = addTwoNumbers2(l1, l2);
	printf("display result\n");
	display(result);

	free_list(l1);
	free_list(l2);
	free_list(result);

	return 0;
}
