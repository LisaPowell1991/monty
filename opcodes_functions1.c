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
	stack_t *new_node;
	int value;

	if (!is_valid_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}



/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the Monty code file.
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = (*stack)->next;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
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
