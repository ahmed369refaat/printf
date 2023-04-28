#include "main.h"
#include "holberton.h"
#include <stdarg.h>

/**
 * _printf - Prints output according to a format
 * @format: A pointer to a string of chars to be printed.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			switch (format[i + 1])
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					i++;
					break;
				case 's':
					len += _puts(va_arg(args, char *));
					i++;
					break;
				case '%':
					len += _putchar('%');
					i++;
					break;
				default:
					len += _putchar(format[i]);
					break;
			}
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
