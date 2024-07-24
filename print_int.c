#include "main.h"

/**
 * print_int - Prints an integer to the buffer
 * @args: Va_list containing the integer to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int print_int(va_list args, char *buffer, int *buf_index)
{
int n = va_arg(args, int);
int count = 0;
unsigned int num;

if (n < 0)
{
if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = '-';
count++;
num = (unsigned int)(-n);
}
else
{
num = (unsigned int)n;
}

count += print_unsigned(num, buffer, buf_index);

return count;
}
