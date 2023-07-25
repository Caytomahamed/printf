#include "main.h"

int _printstring(char *s);
/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	int count = 0, c;
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
				c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				count += _printstring(s);
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _printstring - Prints a string to stdout
 *
 * @s: Pointer to the string to be printed
 *
 * Return: The number of characters printed
 */

int _printstring(char *s)
{
	int count = 0;
	
	while (*s)
	{
		_putchar(*s++);
		count++;
	}
	return (count);
}
