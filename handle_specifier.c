#include "main.h"

/**
 * handle_specifier - Handles the conversion specifier
 * @format: The format string
 * @args: Va_list containing the argument to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int handle_specifier(const char *format, va_list args, char *buffer, int *buf_index)
{
int count = 0;

switch (*format)
{
case 'c':
count = print_char(args, buffer, buf_index);
break;
case 's':
count = print_string(args, buffer, buf_index);
break;
case 'S':
count = print_special_string(args, buffer, buf_index);
break;
case '%':
count = print_percent(args, buffer, buf_index);
break;
case 'd':
case 'i':
count = print_int(args, buffer, buf_index);
break;
case 'u':
count = print_unsigned(va_arg(args, unsigned int), buffer, buf_index);
break;
case 'o':
count = print_octal(va_arg(args, unsigned int), buffer, buf_index);
break;
case 'x':
count = print_hex(va_arg(args, unsigned int), buffer, buf_index);
break;
case 'X':
count = print_hex_upper(va_arg(args, unsigned int), buffer, buf_index);
break;
case 'b':
count = print_binary(args, buffer, buf_index);
break;
default:
if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = '%';
buffer[(*buf_index)++] = *format;
count = 2;
break;
}

return (count);
}
