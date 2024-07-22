#include "main.h"

/**
 * print_char - Print a single character
 * @c: Character to print
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(char c)
{
return (write(1, &c, 1));
}

/**
 * print_string - Print a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
int count = 0;

while (*str)
{
count += print_char(*str);
str++;
}

return (count);
}
