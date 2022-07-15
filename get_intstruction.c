#include "monty.h"
/**
 * get_op_func - return the function of the opcode
 * @command: the opcode
 * Return: pointer to the function
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i = 0;
	
	while (instruction[i].opcode != NULL)
	{
		if (strcmp(instruction[i].opcode, opcode) == 0)
			return (instruction[i].f);
		i++;
	}
	return (NULL);
}
