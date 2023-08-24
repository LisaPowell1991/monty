#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_MALLOC_FAILED "Error: malloc failed\n"
#define ERROR_PINT_EMPTY_STACK "L%d: can't pint, stack empty\n"
#define ERROR_POP_EMPTY_STACK "L%d: can't pop an empty stack\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*opcodes_functions1.c*/
void push(stack_t **stack, int value, unsigned int line_num);
void handle_malloc_failure();
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);

/*opcodes_function2.c*/
void swap(stack_t **stack, unsigned int line_num);

/* execute_opcodes.c */
void execute_instruction(char *opcode, int value,stack_t **stack, unsigned int line_num);

#endif /* MONTY_H */
