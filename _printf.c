#include "main.h"
int convert_matchs(va_list *args, char c);
/**
 * _printf - prints formatted output to stdout
 * @format: format string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *const format, ...)
{
	va_list args;
	int i = 0, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			len += convert_matchs(&args, format[i]);
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);

	return (len);
}

/**
 * convert_matchs - selects the correct function to perform the conversion
 * @args: va_list containing the arguments to convert
 * @c: conversion specifier to look for
 *
 * Return: the number of characters printed by the conversion function
 */
int convert_matchs(va_list *args, char c)
{
	convert_match funcs[] = {
		{'c', printf_char},
		{'s', printf_string},
		{'%', printf_37},
		{'i', printf_int},
		{'d', printf_dec},
		{'r', printf_srev},
		{'R', printf_rot13},
		{'b', printf_bin},
		{'u', printf_unsigned},
		{'o', printf_oct},
		{'x', printf_hex},
		{'X', printf_HEX},
		{'S', printf_exclusive_string},
		{'p', printf_pointer},
		{0, NULL}};
	int i = 0;

	while (funcs[i].f != NULL)
	{
		if (funcs[i].id == c)
			return (funcs[i].f(args));
		i++;
	}

	return (-1);
}
