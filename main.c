#include "monty.h"

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on successful execution,
 * or EXIT_FAILURE on error.
 */

int main(int argc, char *argv[])
{
	char buffer[1024];
	unsigned int line_num = 0;
	char *opcode, *arg;
	int value;
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file))
	{
		line_num++;
		opcode = strtok(buffer, " \t\n");
		if (opcode && opcode[strlen(opcode) - 1] == '$')
			opcode[strlen(opcode) - 1] = '\0';
		if (opcode)
		{
			arg = strtok(NULL, " \t\n");
			value = (arg) ? atoi(arg) : 0;
				execute_instruction(opcode, value, &stack, line_num);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
