#include "main.h"

/**
 * specifier - select which function to be cerformed.
 *
 * @str: the specifier.
 *
 * Return: pointer to the function that corresponds to the specifier given as a
 * parameter. If s does not match any of the expected specifiers return NULL.
 */

int (*specifier(char *str))(va_list args)
{
	spec_t specs[] = {
		{"s", print_string},
		{"c", print_char},
		{"%", print_percentage},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_bin},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_Hex},
		{"S", print_S},
		{"p", print_address},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specs[i].spec)
	{
		if (str && *str == specs[i].spec[0])
			return (specs[i].f);
		i++;
	}
	return (NULL);
}

/**
 * get_func - get the specifier function.
 * @str: the format.
 * @args: the argument.
 * Return: the number printed characters.
 */

int get_func(char *str, va_list args)
{
	int (*f)(va_list args) = specifier(str);

	if (f != NULL)
		return (f(args));

	return (0);
}
