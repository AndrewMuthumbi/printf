#include "main.h"

/**
 * print_int - Prints an integer
 * @args: Va_list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
int n = va_arg(args, int);
int count = 0;
unsigned int num;

if (n < 0)
{
_putchar('-');
count++;
num = (unsigned int)(-n);
}
else
{
num = (unsigned int)n;
}

count += print_unsigned(num);
return (count);
}
