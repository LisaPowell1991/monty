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

void execute_instruction(char *opcode, int value,
		stack_t **stack, unsigned int line_num)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, value, line_num);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}
