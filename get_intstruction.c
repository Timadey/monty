#include "monty.h"
/**
 * get_instruction - return the function of the opcode
 * @command: the opcode
 * Return: pointer to the function
 */
void *(get_intsruction(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t *instruction = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	
	while (intructions != NULL)
	{
		if (strcmp(instruction->opcode, opcode) == 1)
			return (instruction->f);
	}
	return (NULL);
}

