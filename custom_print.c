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

/**
 * print_rot13 - prints the rot13'ed string.
 * @args: the argument passed.
 * Return: the length of the printed characters.
 */

int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int printed_chars = 0, i = 0, j;
	char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (str)
	{
		while (str[i] != '\0')
		{
			for (j = 0; alpha[j] != '\0'; j++)
			{
				if (str[i] == alpha[j])
				{
					printed_chars += fill_buffer(rot[j]);
					break;
				}
			}
			if (!alpha[j])
				printed_chars += fill_buffer(str[i]);
			i++;
		}
	}
	return (printed_chars);
}
