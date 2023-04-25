#include "main.h"
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
	int a = 0;
	int number_of_chars_printed = 0;
	char buf[1024];

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
            		switch (*format)
			{
				case 'c':
					{
						int z = va_arg(args, int);
						buf[a++] = z;
						number_of_chars_printed++;
					}
					break;
				case 's':
					{
						char *s = va_arg(args, char*);

						while (*s != '\0')
						{
							buf[a++] = *s;
							s++;
							number_of_chars_printed++;
						}
					}
					break;
				case '%':
					buf[a++] = '%';
					number_of_chars_printed++;
					break;
			}
		}
		else
		{
			buf[a++] = *format;
			number_of_chars_printed++;
		}
		format++;
	}
	va_end(args);
	fwrite(buf, sizeof(char), a, stdout);
	return (number_of_chars_printed);
}
