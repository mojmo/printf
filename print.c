#include "main.h"

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




