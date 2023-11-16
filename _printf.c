#include "main.h"

/**
 * _printf - custom printf function
 * @format: format specifier
 * 
 * Return: number of char printed (excluding null byte)
*/
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            format++; /** Move to the next character after '%'**/

            switch (*format) {
                case 'c':
                    count += write(1, &va_arg(args, int), 1);
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    int len = 0;
                    while (str[len] != '\0') {
                        len++;
                    }
                    count += write(1, str, len);
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    /***Assuming a reasonable buffer size for simplicity**/
                    char buffer[12]; /** Enough to hold INT_MIN and '\0'**/
                    int len = sprintf(buffer, "%d", num);
                    count += write(1, buffer, len);
                    break;
                }
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, format, 1);
                    break;
            }
        } else {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}

/**
 * main - entry point of the program
 * 
 * Return: 0 on success
*/
int main() {
    /**_printf("Hello, %s! The answer is %d%%\n", "world", 42);**/
    return 0;
}
