#include "monty.h"
/**
 * process_file - function for monty bytecode file processing
 * @filename: file to me processed
 * Return: void
 */
int data_;
void process_file(char *filename)
{
	FILE *file;
	char buffer[1024], *op_str, *argument;
	unsigned int line_number = 0;
	void (*func_pointer)(stack_t **head, unsigned int line_number);
	stack_t *head = NULL;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file))
	{
		line_number++;
		buffer[strcspn(buffer, "\n")] = '\0';
		op_str = strtok(buffer, " \t");
		if (op_str == NULL)
			continue;
		if (!check_opcode(op_str, line_number))
			exit(EXIT_FAILURE);
		if ((strcmp(op_str, "pall") != 0) && strcmp(op_str, "pint") != 0)
		{
			argument = strtok(NULL, " \t");
			if (argument == NULL || !check_argument(argument, op_str, line_number))
				exit(EXIT_FAILURE);
			data_ = atoi(argument);
		}
		func_pointer = get_op_func(op_str);
		func_pointer(&head, line_number);
	}
	fclose(file);
}
