#include "monty.h"
/**
 * op_push -  function pushes items to the stack.
 * @stack: pointer to the head node of the linked list
 * @line_number: file line where instruction was found.
 * Return: number of nodes in the list
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL, *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = data_;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	top = *stack;
	top->prev = new_node;
	new_node->next = top;
	*stack = new_node;
	return;
}

/**
 * op_pall -  function that prints all the elements of a list.
 * @stack: pointer to the head node of the linked list
 * @line_number: file line where instruction was found.
 * Return: number of nodes in the list
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (*stack == NULL)
		return;
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	return;
}

/**
 * op_pint -  function that prints the top element of the stack.
 * @stack: pointer to the head node of the linked list
 * @line_number: file line where instruction was found.
 * Return: number of nodes in the list
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (*stack == NULL)
		return;
	ptr = *stack;
	printf("%d\n", ptr->n);
	return;
}
