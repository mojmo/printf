#include "main.h"

/**
 * print_address - print an address of a pointer.
 * @args: the argument passed.
 * Return: the length of printed characters.
 */

int print_address(va_list args)
{
	char *null = "(nil)";
	void *address = va_arg(args, void *);
	unsigned long num = (unsigned long)address;
	int printed_chars = 0, i = 0, j;
	char local[100];
	char hex[] = "0123456789abcdef";

	if (address == NULL)
		return (_print(null));

	do {
		local[i++] = hex[num % 16];
		num /= 16;
		printed_chars++;
	} while (num != 0);

	local[i] = 'x';
	local[i + 1] = '0';
	local[i + 2] = '\0';

	j = i + 1;

	while (j >= 0)
	{
		fill_buffer(local[j]);
		j--;
	}

	return (printed_chars + 2);
}
