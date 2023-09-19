#include "main.h"

/**
 * print_bin - print a decimal number in binary.
 * @args: the argument passed.
 * Return: the length of the number.
 */

int print_bin(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = printBy_Base(num, 2);

	return (printed_chars);
}

/**
 * print_unsigned - print a positive number.
 * @args: the argument passed.
 * Return: the length of the number.
 */

int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = printBy_Base(num, 10);

	return (printed_chars);
}

/**
 * print_octal - print a number in octal.
 * @args: the argument passed.
 * Return: the length of the number.
 */

int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = printBy_Base(num, 8);

	return (printed_chars);
}

/**
 * print_hex - print a number in hexadecimal with lowercase letters.
 * @args: the argument passed.
 * Return: the length of printed characters.
 */

int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = printBy_Base(num, 16);

	return (printed_chars);
}

/**
 * print_Hex - print a number in hexadecimal with uppercase letters.
 * @args: the argument passed.
 * Return: the length of the printed characters.
 */

int print_Hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = 0, i = 0, j;
	char local[100];
	char HEX[] = "0123456789ABCDEF";

	do {
		local[i++] = HEX[num % 16];
		num /= 16;
		printed_chars++;
	} while (num != 0);

	j = i - 1;

	while (j >= 0)
	{
		fill_buffer(local[j]);
		j--;
	}
	return (printed_chars);
}
