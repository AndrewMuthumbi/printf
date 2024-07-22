#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char *str;

va_start(args, format);

while (format && *format)
{
if (*format != '%')
{
count += print_char(*format);
}
else
{
format++;
if (*format == '\0')
break;
switch (*format)
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
count += print_string(str ? str : "(null)");
break;
case '%':
count += print_char('%');
break;
default:
count += print_char('%');
count += print_char(*format);
}
}
format++;
}

va_end(args);
return (count);
}
