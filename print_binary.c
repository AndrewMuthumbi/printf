#include "main.h"

/**
 * print_binary - Converts an unsigned int argument to binary
 * @args: Va_list containing the unsigned int to convert
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
char buffer[32];
int i = 0;

if (n == 0)
{
_putchar('0');
return (1);
}

while (n > 0)
{
buffer[i++] = (n % 2) + '0';
n /= 2;
}

for (i--; i >= 0; i--)
{
_putchar(buffer[i]);
count++;
}

return (count);
}
