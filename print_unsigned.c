#include "main.h"

/**
 * print_unsigned - Helper function to print unsigned int in decimal
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

/**
 * print_octal - Helper function to print unsigned int in octal
 * @num: Unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int num)
{
int count = 0;

if (num / 8)
count += print_octal(num / 8);

_putchar((num % 8) + '0');
count++;

return (count);
}

/**
 * print_hex - Helper function to print unsigned int in hexadecimal (lowercase)
 * @num: Unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_hex(unsigned int num)
{
int count = 0;
char hex_digits[] = "0123456789abcdef";

if (num / 16)
count += print_hex(num / 16);

_putchar(hex_digits[num % 16]);
count++;

return (count);
}

/**
 * print_hex_upper - Helper function to print unsigned int in hexadecimal (uppercase)
 * @num: Unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_hex_upper(unsigned int num)
{
int count = 0;
char hex_digits[] = "0123456789ABCDEF";

if (num / 16)
count += print_hex_upper(num / 16);

_putchar(hex_digits[num % 16]);
count++;

return (count);
}
