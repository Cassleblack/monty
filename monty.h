#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- The Definations of Struct ---*/
extern int push_arg;

/**
 * struct stack_s - representation of a stack or queue using
 * doubly linked list.
 *
 * @n: An Integer
 * @prev: it will point to the previous element of the stack or queue
 * @next: it will point to the next element of the stack/queue
 * Description: the doubly linked list node strt for
 * stack, queues, LIFO etc.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode's function and itself
 * @opcode: opcode.
 * @f: this will handle the opcode
 * Description: opcode's function and itself for
 * stacks, queues, LIFO, etc.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f) (stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcode's function and itself
 * @file: opcode
 * @push_arg: this function will handle the opcode
 * @buffer: points to the opcode
 * Description: opcode's function and itself
 * for stacks, queues, LIFO etc.
 */

typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

/* The Monty Functions */
void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/* String Funtions */
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

/* Maths Funtions */
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/* The utility Functions */
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);

#endif /* MONTY_H */
