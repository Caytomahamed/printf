#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set argpropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints an array of string characters
 * @str: the variable to print
 *
 * Return: length of the string
 */

int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		_printf("(null)");
		return (6);
	}

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _printf - Produces output according to a format
 * @format: The format of the string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	unsigned int j = 0, n = 0;

	if (format == NULL)
	{
		_printf("(null)\n");
		return (6);
	}

	va_start(arg, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			switch (format[j + 1])
			{
			case 'c':
				_putchar(va_arg(arg, int));
				n++;
				break;
			case 's':
				n += print_string(va_arg(arg, char *));
				break;
			case '%':
				_putchar('%');
				n++;
				break;
			}

			j++;
		}
		else
		{
			_putchar(format[j]);
			n++;
		}
		j++;
	}
	va_end(arg);
	return (n);
}
