#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: format string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count;
	char *str;

	va_list arg;

	va_start(arg, format);

	count = 0;

	while (*format != '\0')
	{

		switch (*format)
		{
		case 'c':
		{
			_putchar(va_arg(arg, int));
			break;
		}
		case 's':
		{
			str = va_arg(arg, char *);
			while (*str != '\0')
			{
				_putchar(*str);
				str++;
			}
			break;
		}
		case '%':
		{
			_putchar('%');
			break;
		}
		}
		format++;
		count++;
	}

	va_end(arg);
	return (count);
}
