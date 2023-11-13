#include "main.h"

/**
 * _printf - custom printf function
 * @format: format specifier
 * 
 * Return: number of char printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
	int chrCount = 0;
	va_list argsLst;

	if(format == NULL)
		return -1;

	va_start(argsLst, format);

	while(*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			chrCount++;
		}
		else 
		{
			format++; 
			if (*format =='\0')
				break;
			
			if(*format == '%')
			{
				write(1, format, 1);
				chrCount++;
			}
			else if (*format == 'c')
			{
				char charact = va_arg(argsLst, int);
				write(1, &charact, 1);
				chrCount++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(argsLst, char*);
				int strLength = strlen(str);

				write(1, str, strLength);
				chrCount += strLength;
			}
		}
		
		format++;
	}

	va_end (argsLst);

	return chrCount;
}

