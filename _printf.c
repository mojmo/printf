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

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (format[0] == '%' && !spec_check(format[1]))
		return (-1);

	while (form && *form)
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
/**
 * spec_check - check the specifier
 * @ch: the specifier
 * Return: 1 if ch is a specifier 0 if not
 */
int spec_check(char ch)
{
	char spec[] = "cdibuoxXSrR%";
	int i, res;

	for (i = 0; i < 13; i++)
	{
		if (spec[i] == ch)
			res = 1;
		else
			res = 0;
	}
	return (res);
}

