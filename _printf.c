#include "main.h"

/**
* handle_char - Handles the 'c' conversion specifier
* @args: va_list of arguments
* Return: Number of characters printed
*/
int handle_char(va_list args)
{
return (print_char(va_arg(args, int)));
}

/**
* handle_string - Handles the 's' conversion specifier
* @args: va_list of arguments
* Return: Number of characters printed
*/
int handle_string(va_list args)
{
char *str = va_arg(args, char *);
return (print_string(str ? str : "(null)"));
}

/**
* handle_percent - Handles the '%' character
* Return: Number of characters printed
*/
int handle_percent(void)
{
return (print_char('%'));
}

/**
* handle_unknown - Handles unknown conversion specifiers
* @format: The unknown specifier
* Return: Number of characters printed
*/
int handle_unknown(char format)
{
int count = 0;

count += print_char('%');
count += print_char(format);
return (count);
}

/**
* _printf - Custom printf function
* @format: Format string
* Return: Number of characters printed, or -1 on error
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (format == NULL)
return (-1);

va_start(args, format);
while (*format)
{
if (*format != '%')
count += print_char(*format);
else
{
format++;
if (*format == '\0')
{
count += print_char('%');
break;
}
switch (*format)
{
case 'c':
count += handle_char(args);
break;
case 's':
count += handle_string(args);
break;
case '%':
count += handle_percent();
break;
default:
count += handle_unknown(*format);
break;
}
}
format++;
}
va_end(args);
return (count);
}
