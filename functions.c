#include "main.h"

#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024

enum {
    F_MINUS = 1,
    F_PLUS = 2,
    F_SPACE = 4,
    F_HASH = 8,
    F_ZERO = 16
};

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size) {
    int i = 0;

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (buffer != NULL) {
        buffer[i] = c;
        i++;
    } else {
        i += putchar(c);
    }

    return i;
}

int write_number(int is_negative, int i, char buffer[], int flags, int width, int precision, int size) {
    int j, k;
    char pad_char = ' ';
    int pad_count = 0;
    int len = BUFF_SIZE - 2 - i;

    UNUSED(size);

    if (flags & F_ZERO) {
        pad_char = '0';
    }

    if (is_negative) {
        len--;
    }

    if (precision > len) {
        pad_count = precision - len;
        len = precision;
    }

    if (width > len) {
        pad_count += width - len;
    }

    if (!(flags & F_MINUS)) {
        for (j = 0; j < pad_count; j++) {
            putchar(pad_char);
        }
    }

    if (is_negative) {
        putchar('-');
    }

    if (buffer != NULL) {
        for (k = BUFF_SIZE - 2 - len; k < i; k++) {
            putchar(buffer[k]);
        }
    }

    for (j = 0; j < pad_count; j++) {
        putchar(pad_char);
    }

    if (buffer == NULL) {
        return len;
    } else {
        return len + pad_count;
    }
}

long int convert_size_number(long int num, int size) {
    switch (size) {
        case 1:
            return (char)num;
        case 2:
            return (short int)num;
        case 3:
        case 0:
            return num;
        case 4:
            return (long int)num;
        default:
            return num;
    }
}

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size) {
    char c = va_arg(types, int);
    return handle_write_char(c, buffer, flags, width, precision, size);
}

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size) {
    int length = 0, i;
    char *str = va_arg(types, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL) {
        str = "(null)";
        if (precision >= 6) {
            str = "      ";
        }
    }

    while (str[length] != '\0') {
        length++;
    }

    if (precision >= 0 && precision < length) {
        length = precision;
    }

    if (width > length) {
        if (flags & F_MINUS) {
            putchar(str[0]);
            for (i = width - length; i > 0; i--) {
                putchar(' ');
            }
            return width;
        } else {
            for (i = width - length; i > 0; i--) {
               
