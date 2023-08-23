#include "monty.h"

/**
 * free_stack - Frees all nodes in the stack
 * @stack: Pointer to the top of the stack.
 *
 * Return: Void
 */

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
