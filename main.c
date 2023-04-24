#include <limits.h>
#include "main.h"
#include <stdio.h>



int main(void)
{
	int len;
    	unsigned int ui;
  
	len = _printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;

	_printf("Negative:[%d]\n", -762534);
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Let's try to printf a simple sentence.\n");
	_printf("String:[%s]\n", "I am a string !");
	return(0);
}
