#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define CLEAR_BUFFER -1

/**
 * struct select_specifier - Struct select specifier.
 *
 * @spec: The specifier.
 * @f: The function associated.
 */

typedef struct select_specifier
{
	char *spec;
	int (*f)(va_list);
} spec_t;

int fill_buffer(int ch);

int print_string(va_list args);
int print_char(va_list args);
int print_percentage(va_list args);
int print_integer(va_list args);
int print_bin(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_Hex(va_list args);
int printBy_Base(unsigned int num, int base);
int print_S(va_list args);
char *handle_S(long int num, int base);

int (*specifier(char *str))(va_list args);
int get_func(char *str, va_list args);
int _printf(const char *format, ...);

#endif
