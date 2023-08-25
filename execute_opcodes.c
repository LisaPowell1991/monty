#include "monty.h"

/**
 * execute_instruction - Executes the given Monty opcode
 * @opcode: Opcode to be executed
 * @value: Value associate with the opcode (if applicable)
 * @line_num: Line number in the monty file.
 * @arg: argument type
 * @stack: A double pointer to the head of the stack.
 * Return: Executes the given opcode,
 * or error message if opcode is not recognised.
 */
void execute_instruction(char *opcode, int value, char *arg,
		stack_t **stack, unsigned int line_num)
{
	(void)value;

	if (strcmp(opcode, "push") == 0)
		push(stack, arg, line_num);
	else if (strcmp(opcode, "pall") == 0)
		pall(*stack);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_num);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_num);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_num);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_num);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_num, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_valid_integer - checks if char is int
 * @str: character being passed in
 *
 * Return: true or false depending on success
 */
bool is_valid_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (false);
	}

	if (*str == '-')
	{
		str++;
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (false);
		}
		str++;
	}

	return (true);
}
