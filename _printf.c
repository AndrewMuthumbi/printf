#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Print a single character to stdout
 * @c: Character to print
 * @count: Pointer to the counter for characters printed
 */
void print_char(char c, int *count)
{
write(1, &c, 1);
(*count)++;
}

/**
 * print_string - Print a string to stdout
 * @str: String to print
 * @count: Pointer to the counter for characters printed
 */
void print_string(char *str, int *count)
{
while (*str)
{
write(1, str, 1);
str++;
(*count)++;
}
}

/**
 * print_percent - Print a literal '%' to stdout
 * @count: Pointer to the counter for characters printed
 */
void print_percent(int *count)
{
write(1, "%", 1);
(*count)++;
}

/**
 * _printf - Print formatted output to stdout
 * @format: Format string
 *
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
print_char(*format, &count);
else
{
format++;
if (*format == 'c')
print_char(va_arg(args, int), &count);

else if (*format == 's')
print_string(va_arg(args, char *), &count);
else if (*format == '%')
print_percent(&count);
}
format++;
}

va_end(args);

return (count);
}
