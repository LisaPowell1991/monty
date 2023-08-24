#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *top_node = NULL;
	int top_value = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	top_node = *stack;
	top_value = top_node->n;

	top_node->n = top_node->next->n;
	top_node->next->n = top_value;
}
