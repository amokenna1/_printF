#include "main.h"

int _printf(const char *format, ...)
{
	int chr_Print = 0;

	va_list args_lst;

	if(format == NULL)
		return (-1);

	va_start(args_lst, format);

	while(*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			chr_Print++;
		}
		else 
		{
			format++; 
			if (*format =='\0')
				break;
			
			if(*format == '%')
			{
				write(1, format, 1);
				chr_Print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_lst, int);
				write(1, &c, 1);
				chr_Print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_lst, char*);
				int str_length = strlen(str);

				write(1, str, str_length);
				chr_Print += str_length;
			}
		}
		
		format++;
	}

	va_end (args_lst);

	return chr_Print;
}

int main()
{
	printf("Miracle\0");
}