#include "main.h"

/**
 * _print - print a string.
 * @str: the string.
 * Return: the length of the string.
 */

int _print(char *str)
{
	int len = 0;

	while (*str)
	{
		fill_buffer(*str);
		len++;
		str++;
	}

	return (len - 1);
}

/**
 * fill_buffer - writes the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int fill_buffer(int ch)
{
	static char buffer[BUFFER_SIZE];
	static int index;

	if (ch == -1 || (index >= BUFFER_SIZE))
	{
		write(1, buffer, index);
		index = 0;
	}

	if (ch != -1)
		buffer[index++] = ch;

	return (1);
}




