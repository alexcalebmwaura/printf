#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format,...)
{
	int i = 0;
	int j = 0;
	va_list args;
	char *buffer = (char *)malloc(1024 * sizeof(char));

	if (buffer == NULL)
	{
		return(-1);
	}
	
	va_start(args, format);
	while(format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			handle_format_specifier(format[i], args, buffer, &j);
		}
		else if(format[i] == '\\')
		{
			i++;
			switch (format[i])
			{
				case 'n':
					{
						buffer[j++] = '\n';
					}
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buffer, j, 1, stdout);
	va_end(args);
	free(buffer);
	return (j);
}

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
char * _itoa(int i, char *strout, int base)
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
		*strr = (digit > 9) ? ('A' + digit -10) : '0' + digit;
		i = i / base;
		strr++;
	}
	if (sign)
	{
		*strr++ = '-';
	}
	*strr = '\0';
	str_rev(strout);
	return (strout);
}
char *str_rev (char *str)
{
	int i = 0;
	int len = 0;
	char c;
	
	if(!str)
		return (NULL);
	while (str[len] != '\0')
	{
		len++;
	}
	while (i < (len/2))
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
	return (str);
}
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
