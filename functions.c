#include "main.h"


/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
    char c = (char)va_arg(types, int);
    buffer[0] = c;
    return handle_print(buffer, 1, flags, width);
}



/************************* PRINT STRING *************************/

/**

 * print_string - Prints a string

 * @types: List a of arguments

 * @buffer: Buffer array to handle print

 * @flags: Calculates active flags

 * @width: Width

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */

int print_string(va_list types, char buffer[],

                int flags, int width, int precision, int size)

{

        char *str = va_arg(types, char *);

        if (str == NULL)

                str = "(null)";


        return (handle_write_string(str, buffer, flags, width, precision, size));

}

/************************* PRINT INT *************************/

/**

 * print_int - Print int

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width.

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */


int main() {
    int num = 42;
    printf("%d", num);  // prints "42"
    return 0;
}



/************************* PRINT BINARY *************************/

/**

 * print_binary - Prints an unsigned number

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width.

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Numbers of char printed.

 */

void print_binary(unsigned int num) {
    int i;
    for (i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}
