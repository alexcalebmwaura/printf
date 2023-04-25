#include <limits.h>
#include "main.h"
#include <stdio.h>



int main(void)
{
	int len;
    	unsigned int ui;
	void *addr;

	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;

	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	_printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("String:[%s]\n", "I am a string !");
	_printf("Unsigned:[%u]\n", ui);
	_printf("Character:[%c]\n", 'H');
	 _printf("Address:[%p]\n", addr);
	 len = _printf("Percent:[%%]\n");
	 _printf("Len:[%d]\n", len);
	 _printf("Unknown:[%r]\n");
	return(0);
}
