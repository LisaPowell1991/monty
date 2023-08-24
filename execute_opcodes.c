#include "monty.h"

/**
 * execute_instruction - Executes the given Monty opcode
 * @opcode: Opcode to be executed
 * @value: Value associate with the opcode (if applicable)
 * @line_num: Line number in the monty file.
 * @stack: A double pointer to the head of the stack.
 * Return: Executes the given opcode,
 * or error message if opcode is not recognised.
 */

void execute_instruction(char *opcode, int value, char *arg,
		stack_t **stack, unsigned int line_num)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (value == 0 && strcmp(arg, "0") != 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		push(stack, value, line_num);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_num);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_num);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_num);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_num);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}

int is_integer(const char *str)
{
    int i = 0;
    if (str[0] == '-')
        i = 1;
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}
