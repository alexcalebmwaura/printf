#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
char * _itoa(int i, char *strout, int base);
char *_strcpy(char *dest, char *src);
char *str_rev (char *str);
int _strlen(char *s);
int handle_format_specifier(char specifier, va_list args, char *buffer, int *j);
#endif


