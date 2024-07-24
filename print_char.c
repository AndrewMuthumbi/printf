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