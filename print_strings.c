#include "main.h"

/**
 * print_char - print a character.
 * @args: the argument passed to _printf function.
 * Return: the number of chars printed.
 */

int print_char(va_list args)
{
	int printed_chars = 0;
	char ch = va_arg(args, int);

	printed_chars += fill_buffer(ch);
	return (printed_chars);
}

/**
 * print_percentage - print a %.
 * @args: the argument passed.
 * Return: the number of chars printed.
 */

int print_percentage(__attribute__((unused)) va_list args)
{
	int printed_chars = 0;

	printed_chars += fill_buffer('%');

	return (printed_chars);
}

/**
 * print_string - print a string.
 * @args: argument passed.
 * Return: the number of printed characters.
 */

int print_string(va_list args)
{
	int printed_chars = 0;
	char *str = va_arg(args, char *);
	char *null = "(null)";

	if (str == NULL)
		str = null;

	while (*str)
	{
		printed_chars += fill_buffer(*str);
		str++;
	}
	return (printed_chars);
}
