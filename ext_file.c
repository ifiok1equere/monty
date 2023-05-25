#include "monty.h"

/**
 * ext - function checks that correct extension file
 * @filename: name of file
 * Return: integer
 */

int ext_check(char *filename)
{
	char *extension = strrchr(filename, '.');

	if (extension == NULL || strcmp(extension, ".m") != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (0);
	}
	return (1);
}
