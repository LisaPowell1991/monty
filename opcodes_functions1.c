#include "monty.h"

/**
 * push - Pushes n element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @arg: argument value
 * @line_num: Line number in the Monty code file.
 *
 * Return: Void
 */
void push(stack_t **stack, const char *arg, unsigned int line_num)
{
	int value;
	stack_t *new_node;

	/* Validate if arg is a valid integer */
	if (!arg || !arg[0])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer */
	value = atoi(arg);

	/* Create a new node */
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = *stack;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: void
 */

void pall(stack_t *stack)
{
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->prev;
	}
}

/**
 * pint - Prints the value at the top the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: Void
 * Or if the stack is empty print error message
 * and exits with EXIT_FAILURE
 */

void pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pop - Removes the top element from the stack.
 * @stack: Double pointer to the top the stack.
 * @line_num: Line number of the opcode in the file.
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
