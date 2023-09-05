#include "main.h"
/**
 * _push - push element to stack
 * @stack: pointer to stack
 * @ln_num: line number
*/

void _push(stack_t **stack, unsigned int ln_num)
{
	int value = 0;

	/* Check if stack is empty; sanity checks */
	if (*stack == NULL)
	{
		printf("L%d: usage: push integer\n", ln_num);
		EXIT_FAILURE;
	}
	/* Check if value is integer */
	value = atoi((*stack)->n);
	if (value == 0)
	{
		printf("L%d: usage: push integer\n", ln_num);
		EXIT_FAILURE;
	}

	add_dnodeint(stack, value);
}

/**
 * _pall - print all elements of stack
 * @stack: pointer to stack
 * @ln_num: line number
 */

void _pall(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp = NULL;

	/* Check if stack is empty */
	if (*stack == NULL)
	{
		printf("L%d: can't pall, stack empty\n", ln_num);
		EXIT_FAILURE;
	}
	/* Print all elements of stack */
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _add - add top two elements of stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: result stored in second element
 */

void _add (stack_t **stack, unsigned int ln_num)
{
	/* Declare temp node pointer */
	stack_t *temp = NULL;
	int sum = 0;

	/* Check if stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", ln_num);
		EXIT_FAILURE;
	}
	/* Add top two elements jiggery pokery */
	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}