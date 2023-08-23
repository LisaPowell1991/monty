#include "monty.h"

/**
 * push - Pushes n element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: Value to be pushed onto the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: Void
 */
void push(stack_t **stack, int value, unsigned int line_num)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void)line_num;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		handle_malloc_failure();
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * handle_malloc_failure - Handles malloc failure
 * by printing an error message
 * and exiting with failure status.
 *
 * Return: Void
 */
void handle_malloc_failure(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	(void)line_num;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: The value at the top of the stack.
 * Or if the stack is empty print error message
 * and exits with EXIT_FAILURE
 */

void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
