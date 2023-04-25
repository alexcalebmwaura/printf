#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
char  *_itoa(long int i, char *strout, int base);
char *_strcpy(char *dest, char *src);
char *str_rev(char *str);
int _strlen(char *s);
char *itoa_(long int i, char *strout, int base);
int handle_format(char specifier, va_list args, char *buffer, int *j);
int handle_format2(char specifier, va_list args, char *buffer, int *j);
#endif


