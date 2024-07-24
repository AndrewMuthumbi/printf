#include "main.h"

/**
 * handle_specifier - Handles each format specifier
 * @format: Format string containing the characters and specifiers
 * @args: List of arguments to be printed
 * @count: Pointer to count of characters printed
 *
 * Return: Number of characters printed
 */
int handle_specifier(const char *format, va_list args, int *count)
{
switch (*format)
{
case 'c':
*count += print_char(args);
break;
case 's':
*count += print_string(args);
break;
case '%':
*count += print_percent(args);
break;
case 'd':
case 'i':
*count += print_int(args);
break;
case 'u':
*count += print_unsigned(va_arg(args, unsigned int));
break;
case 'o':
*count += print_octal(va_arg(args, unsigned int));
break;
case 'x':
*count += print_hex(va_arg(args, unsigned int));
break;
case 'X':
*count += print_hex_upper(va_arg(args, unsigned int));
break;
case 'b':
*count += print_binary(args);
break;
default:
_putchar('%');
_putchar(*format);
*count += 2;
break;
}
return (*count);
}
