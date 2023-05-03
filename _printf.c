#include "main.h"
#include <stdio.h>
#include <stdarg.h>
void print_buffer(char buffer[], int *buff_ind);
/**
 * myprintf - Printf function.
 * Return: Printed chars.
 */
int myprintf(const char *format, ...)
{
va_list p;
va_start(p, format);
int i = 0;
while (format[i])
{
if (format[i] == '%')
i++;
switch (format[i])
{
case 'd':
{
int x = va_arg(p, int);
printf("%d", x);
break;
}
case 'f':
{
double x = va_arg(p, double);
printf("%f", x);
break;
}
case 'c':
{
int x = va_arg(p, char);
printf("%c", x);
break;
}
case 's':
{
char *x = va_arg(p, char*);
printf("%s", x);
break;
}
case 'x':
case 'X':
{
int x = va_arg(p, int);
printf("%x", x);
break;
}
case 'p':
{
void *x = va_arg(p, void*);
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
va_end(p);
return 0;
}
