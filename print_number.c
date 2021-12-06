#include "simpleshell.h"

/**
  * print_number - Function that prints an integer
  * @n: a number
  * Return: Nothing
  */
void print_number(unsigned int n)
{
	if (n / 10)
		print_number(n / 10);
	_putchar(n % 10 + '0');
}
