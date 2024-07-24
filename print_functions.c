#include "main.h"

/**
 * print_char - Prints a single character
 * @args: Va_list containing the character to print
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args)
{
char c = va_arg(args, int);

return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: Va_list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;

if (str == NULL)
str = "(null)";
while (str[len])
{
_putchar(str[len]);
len++;
}
return (len);
}

/**
 * print_percent - Prints a percent sign
 * @args: Va_list (unused)
 *
 * Return: Number of characters printed (always 1)
 */
int print_percent(va_list args)
{
(void)args;
return (_putchar('%'));
}

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
