#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * _printf -function to print fomarted output
 * @format: the output to be printed
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int j = 0;
	va_list args;
	char *buffer = (char *)malloc(1024 * sizeof(char));

	if (buffer == NULL)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'i' || format[i] == 'd'
					|| format[i] == 'o' 
					||format[i] == 'R' || format[i] == 's'
					|| format[i] == 'b')
				handle_format(format[i], args, buffer, &j);
			else
				handle_format2(format[i], args, buffer, &j);
		}
		else if (format[i] == '\\')
		{
			i++;
			switch (format[i])
			{
				case 'n':
						buffer[j++] = '\n';
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
/**
 * _strlen - function to calculate length of string
 * @s: the string
 * Return: length of string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
/**
 * str_rev - function to reverse a string
 * @str: the string
 * Return: the reversed string
 */
char *str_rev(char *str)
{
	int i = 0;
	int len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
	{
		len++;
	}
	while (i < (len / 2))
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
	return (str);
}
/**
 * _strcpy - function to copy string to a different memory location
 * @dest: destination string
 * @src: source string
 * Return: destination string
 */
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
