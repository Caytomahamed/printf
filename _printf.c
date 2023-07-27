#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _strlen(char *s);
void _printBuffer(char *c, long unsigned int n);

/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	long unsigned int len;
	char *s;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				_printBuffer(&c, 1);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				len = _strlen(s);
				_printBuffer(s, len);
				count += len;
			}
			else if (*format == '%')
			{
				_printBuffer("%", 1);
				count++;
			}
		}
		else
		{
			_printBuffer((char *)format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _strlen - Returns the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _printBuffer - Prints a buffer to stdout
 * @c: the buffer to print
 * @n: the number of characters to print
 *
 * Return: void
 */
void _printBuffer(char *c, long unsigned int n)
{
	if (n > 0)
		write(1, c, n);
}
