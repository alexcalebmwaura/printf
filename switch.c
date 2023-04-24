#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int handle_format_specifier(char specify, va_list args, char *buffer, int *j)
{
	char *str;
	char *tmp = (char *)malloc(100 * sizeof(char)); 
	
	if (tmp == NULL)
		return (-1);
	switch (specify)
	{
		case 'c':
				buffer[*j] = va_arg(args, int);
				(*j)++;
				break;
		case 'd':
		case 'i':
				_itoa(va_arg(args, int), tmp ,10);
				_strcpy(&buffer[*j],tmp);
				*j += _strlen(tmp);
				break;
		case 'x':
		case 'X':
				 _itoa(va_arg(args, int), tmp ,16);
                                _strcpy(&buffer[*j],tmp);
                                *j += _strlen(tmp);
                                break;
		case 'o':
		case 'O':
				tmp = _itoa(va_arg(args, int), tmp, 8);
                                _strcpy(&buffer[*j],tmp);
                                *j += _strlen(tmp);
                                break;
		case 's':
				str = va_arg(args, char *);
				_strcpy(&buffer[*j],str);
				*j += _strlen(str);
				break;
	}
	free (tmp);
	return (0);
}
