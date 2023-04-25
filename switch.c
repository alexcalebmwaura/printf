#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * handle_format - function to format and print d,i,o,s
 * @specify: formart specifier
 * @args: variable argument list
 * @buffer: memory to store formatted string
 * @j: size of j
 * Return: 0
 */
int handle_format(char specify, va_list args, char *buffer, int *j)
{
	char *str;
	char *tmp = (char *)malloc(100 * sizeof(char));

	if (tmp == NULL)
		return (-1);
	switch (specify)
	{
		case 'd':
		case 'i':
				_itoa(va_arg(args, int), tmp, 10);
				_strcpy(&buffer[*j], tmp);
				*j += _strlen(tmp);
				break;
		case 'o':
				_itoa(va_arg(args, unsigned int), tmp, 8);
				_strcpy(&buffer[*j], tmp);
				*j += _strlen(tmp);
				break;
		case 's':
				str = va_arg(args, char *);
				_strcpy(&buffer[*j], str);
				*j += _strlen(str);
				break;
	}
	free(tmp);
	return (0);
}
/**
 * handle_format2 - function to format and print d,i,o,s
 * @specify: formart specifier
 * @args: variable argument list
 * @buffer: memory to store formatted string
 * @j: size of buffer
 * Return: 0
 */
int handle_format2(char specify, va_list args, char *buffer, int *j)
{
	char *tmp2 = (char *)malloc(100 * sizeof(char));
	char s = specify;

	if (tmp2 == NULL)
		return (-1);
	switch (specify)
	{
		case 'c':
			buffer[*j] = va_arg(args, int);
			(*j)++;
			break;
		case 'X':
			_itoa(va_arg(args, unsigned int), tmp2, 16);
			_strcpy(&buffer[*j], tmp2);
			*j += _strlen(tmp2);
			break;
		case 'x':
			itoa_(va_arg(args, unsigned int), tmp2, 16);
			_strcpy(&buffer[*j], tmp2);
			*j += _strlen(tmp2);
			break;
		case 'u':
			_itoa(va_arg(args, unsigned int), tmp2, 10);
			_strcpy(&buffer[*j], tmp2);
			*j += _strlen(tmp2);
			break;
		case 'p':
			itoa_((long int)va_arg(args, void *), tmp2, 16);
			_strcpy(&buffer[*j], "0x");
			*j += 2;
			_strcpy(&buffer[*j], tmp2);
			*j += _strlen(tmp2);
			break;
		default:
			_strcpy(&buffer[*j], &s);
			*j += 1;
			break;
	}
	free(tmp2);
	return (0);
}

/**
 * _itoa - fnction toconvert integer to character(hex uppercase)
 * @i: the int to convert
 * @strout: the string to be printed
 * @base: base to convert no to
 * Return: number in string format
 */
char *_itoa(long int i, char *strout, int base)
{
	char *strr = strout;
	int digit;
	int sign = 0;
	int k = 0;

	if (i == 0)
	{
		strout[k++] = '0';
		strout[k] = '\0';
		return (strout);
	}
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*strr++ = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
	}
	if (sign)
	{
		*strr++ = '-';
	}
	*strr = '\0';
	str_rev(strout);
	return (strout);

}
/**
 * itoa_ - fnction toconvert integer to character(hex lowercase)
 * @i: the int to convert
 * @strout: the string to be printed
 * @base: base to convert no to
 * Return: number in string format
 */
char *itoa_(long int i, char *strout, int base)
{
	char *strr = strout;
	int digit;
	int sign = 0;
	int j = 0;

	if (i == 0)
	{
		strout[k++] = '0';
		strout[i] = '\0';
	}
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*strr++ = (digit > 9) ? ('a' + digit - 10) : '0' + digit;
		i = i / base;
	}
	if (sign)
	{
		*strr++ = '-';
	}
	*strr = '\0';
	str_rev(strout);
	return (strout);
}

