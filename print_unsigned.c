#include "main.h"

/**
 * print_unsigned - Helper function to print unsigned int
 * @num: Unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int num)
{
int count = 0;

if (num / 10)
count += print_unsigned(num / 10);

_putchar((num % 10) + '0');
count++;

return (count);
}
