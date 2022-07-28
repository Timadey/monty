#ifndef _MONTY_H_
#define _MONTY_H_
#define TOK_SIZE 3
#define TOK_DELIM " \n\t\r\v\f"
/**
 * Standard libraries
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
/**
 * destruct.c
 */
void destructor() __attribute__((destructor));
void fail_exit(int status);
/**
 * helper functions defined in helpers.c
 */
void check_malloc(void *mem);
char **tokenize_line(char *ln);
int is_int(char *str);
void free_stack();
/**
 * instruction.c
 */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
/**
 * get_instruction.c
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number);
/**
 * run_monty.c
 */
void run_monty(char **tokens);
#endif
