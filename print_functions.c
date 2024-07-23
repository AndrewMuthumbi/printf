#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
char c = va_arg(args, int);

return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
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
 * @args: List of arguments (unused)
 *
 * Return: Number of characters printed
 */
int print_percent(va_list args)
{
(void)args;
return (_putchar('%'));
}
