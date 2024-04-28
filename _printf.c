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
if (*format == 'b')
{
unsigned int num = va_arg(args, unsigned int);
char buffer[33];
/* Set buffer size according to the maximum binary rep length (32 bits + '\0')*/
int i = 0;

/* Convert the integer to binary representation*/
while (num > 0)
{
buffer[i++] = (num & 1) + '0';
num >>= 1;
}
/* Append the null terminator*/
buffer[i] = '\0';
/* Reverse the string*/
int length = i;
for (int j = 0; j < length / 2; j++)
{
char temp = buffer[j];
buffer[j] = buffer[length - j - 1];
buffer[length - j - 1] = temp;
}
/* Write the binary representation to stdout*/
write(1, buffer, length);
count += length;
}
}
format++;
}

va_end(args);

return (count);
}
