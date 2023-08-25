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

/**
 * add - Adds the top 2 elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the monty code file.
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_num)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_num);
}

/**
 * nop - Doesn't do anything
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: Void
 */

void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: A pointer to the pointer to the top of the stack
 * @line_num: The current line number being processed
 */
void sub(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_num);
}
