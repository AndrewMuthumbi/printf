#include "main.h"

/**
 * get_print_func - Selects the correct function for printing
 * @s: The format specifier
 *
 * Return: A pointer to the printing function
 */
static int (*get_print_func(char s))(va_list)
{
print_t funcs[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'\0', NULL}
};
int i = 0;

while (funcs[i].spec != '\0')
{
if (funcs[i].spec == s)
return (funcs[i].f);
i++;
}
return (NULL);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
int (*print_func)(va_list);

va_start(args, format);
while (format && format[i])
{
if (format[i] != '%')
{
_putchar(format[i]);
count++;
}
 else
{
i++;
if (format[i] == '\0')
return (-1);
print_func = get_print_func(format[i]);
if (print_func)
count += print_func(args);
else
{
_putchar('%');

_putchar(format[i]);
count += 2;
}
}
i++;
}
va_end(args);
return (count);
}
