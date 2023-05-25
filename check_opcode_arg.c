#include "monty.h"
/**
 * check_argument - checks if monty opcode arg is a number
 * @str: pointer to the opcode number argument
 * @line_number: line with opcode instruction
 * Return: 1 if is a number, 0 if it is not
 */
int check_argument(char *str, unsigned int line_number)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * check_opcode - function checks validity of monty opcode
 * @opcode: code instruction to be implemented
 * @line_number: line_number where opcode was fetched
 * Return: 1 if it is valid, 0 if it is not
 */

int check_opcode(char *opcode, int line_number)
{
	int opcode_count, i;

	/* List of valid opcodes */
	char *opcode_list[] = {"push", "pall", "pint"};

	/* Count the number of valid opcodes in the array */
	opcode_count = sizeof(opcode_list) / sizeof(opcode_list[0]);

	/* Check if the opcode parsed into the function is valid */
	for (i = 0; i < opcode_count; i++)
	{
		if (strcmp(opcode, opcode_list[i]) == 0)
			return (1);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	return (0);
}

/**
 * _malloc - dynamically allocate memory
 * @buf: pointer to allocated memory
 * Return: pointer to allocated memory
 */

char *_malloc(char *buf)
{
	buf = malloc(1024);
	if (buf == NULL)
	{
		printf("Error: malloc failed");
		return (NULL);
	}
	return (buf);
}
