#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 *
 * @format: a list of types of arguments passed to the function.
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char *form = (char *)format;

	va_start(args, format);

	if (!form || (*form == '%' && (*(form + 1) == '\0' || *(form + 1) == ' ')))
		return (CLEAR_BUFFER);

	while (*form)
	{
		if (*form == '%')
		{
			form++;
			printed_chars += get_func(form, args);
		}
		else
			printed_chars += fill_buffer(*form);
		form++;
	}

	fill_buffer(CLEAR_BUFFER);
	va_end(args);
	return (printed_chars);
}
