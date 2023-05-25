#include "monty.h"
/**
 * main - entry to function
 * @argc: cmdline arg count
 * @argv: cmdline arg vector
 * Return: 0 for success always
 */

int main(int argc, char *argv[])
{
	char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	if (!ext_check(filename))
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	process_file(filename);

	return (0);
}
