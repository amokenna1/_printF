#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

struct fmat {
    char fmat;
    int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct fmat fmat_t;

/**
 * _printf - Custom printf function
 * @format: Format specifier
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...);
int hndlePrint(const char *fmat, int *i,
               va_list list, char buffer[], int flags, int width, int precision, int size);

/* Function prototypes */
int prntChar(va_list types, char buffer[], int flags, int width, int precision, int size);
int printStrng(va_list types, char buffer[], int flags, int width, int precision, int size);
int prntInt(va_list types, char buffer[], int flags, int width, int precision, int size);
int prntPcent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Add prototypes for other functions here */

#endif /* MAIN_H */