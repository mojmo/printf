#include "main.h"

/**
 * print_rev - prints the reversed string.
 * @args: the argument passed.
 * Return: the length of the printed characters.
 */

int print_rev(va_list args)
{
	char *str = va_arg(args, char *);
	int printed_chars = 0, len = 0;

	if (str)
	{
		while (str[len] != '\0')
			len++;

		len = len - 1;

		while (len >= 0)
		{
			printed_chars += fill_buffer(str[len]);
			len--;
		}
	}
	return (printed_chars);
}
