#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * myprintf - Printf function.
 * Return: Printed chars.
 */
int my_printf(const char *format, ...)
{
    va_list args;
    if (format ==NULL)
        return (-1);
    va_start(args, format);

    int i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'd':
                {
                    int x = va_arg(args, int);
                    printf("%d", x);
                    break;
                }
                case 'f':
                {
                    double x = va_arg(args, double);
                    printf("%f", x);
                    break;
                }
                case 'c':
                {
                    int x = va_arg(args, int);
                    printf("%c", x);
                    break;
                }
                case 's':
                {
                    char *x = va_arg(args, char*);
                    printf("%s", x);
                    break;
                }
                case 'x':
                case 'X':
                {
                    int x = va_arg(args, int);
                    printf("%x", x);
                    break;
                }
                case 'p':
                {
                    void *x = va_arg(args, void*);
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
