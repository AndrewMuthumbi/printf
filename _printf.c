#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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
write(1, format, 1);
count++;
}
else
{
format++;
if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
char buffer[20]; 
int length = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, length);
count += length;
}
}
format++;
}

va_end(args);

return (count);
}
