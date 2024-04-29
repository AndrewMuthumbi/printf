#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Print a single character
 * @c: Character to print
 * Return: Number of characters printed (always 1)
 */
int print_char(char c)
{
write(1, &c, 1);
return (1);
}

/**
 * print_string - Print a string
 * @str: String to print
 * Return: Number of characters printed
 */
int print_string(char *str)
{
int count = 0;

while (*str)
{
write(1, str, 1);
str++;
count++;
}

return (count);
}

/**
 * print_percent - Print a literal '%'
 * Return: Always 1 (number of characters printed)
 */
int print_percent(void)
{
write(1, "%", 1);
return (1);
}

/**
 * _printf - Print formatted output to stdout
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format != '%')
{
/* Regular character, just print it */
count += print_char(*format);
}
else
{
/* Format specifier, handle accordingly */
format++;
if (*format == 'c')
{
/* Character argument */
count += print_char(va_arg(args, int));
}
else if (*format == 's')
{
/* String argument */
count += print_string(va_arg(args, char *));
}
else if (*format == '%')
{
/* Literal '%' */
count += print_percent();
}
}
format++;
}

va_end(args);

return (count);
}
