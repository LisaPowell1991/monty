#include "monty.h"

/**
 * free_stack - Frees all nodes in the stack
 * @stack: Pointer to the top of the stack.
 *
 * Return: Void
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
