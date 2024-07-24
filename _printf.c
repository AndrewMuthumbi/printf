#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing the characters and specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
int i = 0, count = 0;
va_list args;

va_start(args, format);
if (format == NULL)
{
return (-1);
}

while (format && format[i])
{
if (format[i] == '%')
{
i++;
handle_specifier(&format[i], args, &count);
}
else
{
_putchar(format[i]);
count++;
}
i++;
}

va_end(args);
return (count);
}
