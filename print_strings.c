#include "main.h"

/**
 * print_char - print a character.
 * @args: the argument passed to _printf function.
 * Return: the number of chars printed.
 */

int print_char(va_list args)
{
	int c = va_arg(args, int);
	int printed_chars = 0;

	printed_chars += fill_buffer(c);

	return (printed_chars);
}

/**
 * print_percentage - print a %.
 * @args: the argument passed.
 * Return: the number of chars printed.
 */

int print_percentage(__attribute__((unused)) va_list args)
{
	return (fill_buffer('%'));
}

/**
 * print_string - print a string.
 * @args: argument passed.
 * Return: the number of printed characters.
 */

int print_string(va_list args)
{
	int printed_chars = 0;
	char *str = va_arg(args, char *), *start;
	char *null = "(null)";

	if (str == NULL)
		str = null;

	start = str;

	while (*str)
	{
		fill_buffer(*str);
		str++;
	}
	printed_chars = str - start;
	return (printed_chars);
}

/**
 * print_S - print non printable characters in hexadecimal.
 * @args: the argument passed.
 * Return: the length of the printed characters.
 */


int print_S(va_list args)
{
	char *str = va_arg(args, char *), *null = "(null)", *hex_val;
	int printed_chars = 0;
	
	if (str == NULL)
		str = null;

	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			printed_chars += fill_buffer('\\');
			printed_chars += fill_buffer('x');
			hex_val = handle_S(*str, 16);
			if (!hex_val[1])
				printed_chars += fill_buffer('0');
			while (*hex_val)
			{
				printed_chars += fill_buffer(*hex_val);
				hex_val++;
			}
		}
		else
			printed_chars += fill_buffer(*str);
		str++;
	}
	return (printed_chars);
}
