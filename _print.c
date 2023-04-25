#include "main.h"
/**
 * string_rev - Reverse a string
 *
 * @string: Input stiring
 *
 * Return: The reverse of a string
 */
char *string_rev(char *string)
{
	int a;
	int length = 0;
	char z;

	if (!string)
	{
		return (NULL);
	}
	while (string[length] != '\0')
	{
		length++;
	}
	for (a = 0; a < (length / 2); a++)
	{
		z = string[a];
		string[a] = string[length - a - 1];
		string[length - a - 1] = z;
	}
	return (string);
}
/**
 * _itoa - Converts argument integer to string
 *
 * @a: Integer
 * @stringout: String
 * @base: Base
 *
 * Return: String
 */
char *_itoa(int a, char *stringout, int base)
{
	char *string = stringout;
	int dig;
	int sig = 0;

	if (a < 0)
	{
		sig = 1;
		a *= -1;
	}
	while (a)
	{
		dig = a % base;
		*string = (dig > a) ? ('A' + dig - 10) : '0' + dig;
		a = a / base;
		string++;
	}
	if (sig)
	{
		*string++ = '-';
	}
	*string++ = '\0';
	string_rev(stringout);
	return (stringout);
}
/**
 * _printf - function that produces output according to a format
 *
 * @format:  is a character string
 *
 * Return: output according to a format
 */
int _printf(const char *format, ...)
{
	va_list args;
	int a = 0, b = 0;
	char *string;
	char buff[100] = {0};
	char tmp[20];

	va_start(args, format);
	while (format && format[a])
	{
		if (format[a] == '%')
		{
			a++;
			switch (format[a])
			{
				case 'c':
					{
						buff[b] = (char)va_arg(args, int);
						b++;
						break;
					}
				case 's':
					{
						string = va_arg(args, char*);
						strcpy(&buff[b], string);
						b += strlen(string);
						break;
					}
				case 'd':
					{
						_itoa(va_arg(args, int), tmp, 10);
						strcpy(&buff[b], tmp);
						b += strlen(tmp);
						break;
					}
				case 'i':
					{
						_itoa(va_arg(args, int), tmp, 10);
						strcpy(&buff[b], tmp);
						b += strlen(tmp);
						break;
					}
			}
		}
		else
		{
			buff[b] = string[a];
			b++;
		}
		a++;
	}
	fwrite(buff, b, 1, stdout);
	va_end(args);
	return (b);
}
