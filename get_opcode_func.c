#include "monty.h"
/**
 * get_op_func - function selects the correct stack function user needs
 * @op_code: parameter represents stact operation to done by user
 * Return: a function pointer
 */

void (*get_op_func(char *op_code))(stack_t **head, unsigned int line_number)
{

	instruction_t ops[] = {{"push", op_push}, {"pall", op_pall},
		{"pint", op_pint}, {NULL, NULL}};
	int i = 0;

	while (i < 3)
	{
		if (strcmp(ops[i].opcode, op_code) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
