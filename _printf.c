#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * myprintf - Printf function.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    int i;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'd':
                {
                    int x = va_arg(list, int);
                    printf("%d", x);
                    break;
                }
                case 'f':
                {
                    double x = va_arg(list, double);
                    printf("%f", x);
                    break;
                }
                case 'c':
                {
                    int x = va_arg(list, int);
                    printf("%c", x);
                    break;
                }
                case 's':
                {
                    char *x = va_arg(list, char*);
                    printf("%s", x);
                    break;
                }
                case 'x':
                case 'X':
                {
                    int x = va_arg(list, int);
                    printf("%x", x);
                    break;
                }
                case 'p':
                {
                    void *x = va_arg(list, void*);
                    printf("%p", x);
                    break;
                }
                case '%':
                    putchar('%');
                    break;
                default:
                    putchar(format[i]);
                    break;
            }
        }
        else
        {
            putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return 0;
}
