#include "main.h"
/**
 * add_dnodeint - add node to beginning of doubly linked list
 * @head: pointer to head of list
 * @n: value to add to node
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	/* Create new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		EXIT_FAILURE;
	}
	/* Assign value to new node */
	new_node->n = n;
	/* Assign new node to top of stack jiggery pokery */
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	return (new_node);
}