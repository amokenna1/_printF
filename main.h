#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format specifier
 * 
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...);

/**
 * binary - Convert a decimal number to binary
 * @num: Decimal number to convert
 * 
 * Return: Binary representation
 */
int binary(int num);

/**
 * octal - Convert a decimal number to octal
 * @num: Decimal number to convert
 * 
 * Return: Octal representation
 */
int octal(int num);

#endif /* MAIN_H */

