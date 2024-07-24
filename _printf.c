#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing the characters and specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
char buffer[BUFFER_SIZE];
int i = 0, count = 0, buf_index = 0;
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
count += handle_specifier(&format[i], args, buffer, &buf_index);
}
else
{
if (buf_index >= BUFFER_SIZE)
{
write(1, buffer, buf_index);
buf_index = 0;
}
buffer[buf_index++] = format[i];
count++;
}

i++;
}

if (buf_index > 0)
{
write(1, buffer, buf_index);
}

va_end(args);
return (count);
}
