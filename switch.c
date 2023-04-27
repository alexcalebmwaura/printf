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
	char *input;
	char *tmp = (char *)malloc(1024 * sizeof(char));

	if (tmp == NULL)
		return (-1);
	switch (specify)
	{
		case 'b':
				_itoa(va_arg(args, int),tmp, 2);
				_strcpy(&buffer[*j], tmp);
				*j += _strlen(tmp);
				break;
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
				while (*str != '\0')
				{
					buffer[*j] =  *str;
					(*j)++;
					str++;
				}
				break;
		case 'R':
				input = va_arg(args, char *);
				rot13(input, tmp);
				_strcpy(&buffer[*j], tmp);
				*j += _strlen(tmp);
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
	char *str;
	char *reversed;

	if (tmp2 == NULL)
		return (-1);
	switch (specify)
	{
		case 'c':
			buffer[*j] = va_arg(args, int);
			(*j)++;
			break;
		case 'r':
			str = va_arg(args, char *);
			_strcpy(tmp2, str);
			reversed = str_rev(tmp2);
			while(*reversed != '\0')
			{
				buffer[*j] = *reversed;
				(*j)++;
				reversed++;
			}
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
		case 'S':
			str = va_arg(args, char *);
			while(*str != '\0')
			{
				if (*str < 32 || *str >= 127)
				{
					_strcpy(&buffer[*j], "\\x");
					(*j) += 2;
					_itoa(*str, tmp2, 16);
					if(_strlen(tmp2) == 1)
					{
						buffer[*j] = '0';
						(*j)++;
					}
					_strcpy(&buffer[*j], tmp2);
					(*j) += _strlen(tmp2);
				}
				else
				{
					buffer[*j] = *str;
					(*j)++;
				}
				str++;
			}
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
	int len = 0;
	int j;

	if (i < 0 && base == 10)
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

	if (sign && base != 10)
	{
		len = _strlen(strout);
		for (j = 0; j < len; j++)
		{
			if (strout[j] == 1)
			{
				strout[j] = '0';
			}
			else if (strout[j] == '0')
			{
				strout[j] = '0';
			}
		}
	}
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
/**
 * ront13 - function to turn a string to rot13
 * @input: input string
 * @output: output string
 * Return: null
 */
void *rot13(char *input, char *output)
{

	int i, j;
	char str[52] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char str2[52] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";

	i = 0;
	while (input[i] != '\0')
	{
		if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
		{
			j = 0;
			while (input[i] != str[j] && j < 52)
				j++;

			output[i] = str2[j];
		}
		else
		{
			output[i] = input[i];
		}
		i++;
	}
	output[i] = '\0';
	return (0);
}
