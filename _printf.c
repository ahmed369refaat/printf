#include "main.h"
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
              
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
