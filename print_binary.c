#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary
 * @args: Va_list containing the unsigned int to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args, char *buffer, int *buf_index)
{
unsigned int num = va_arg(args, unsigned int);
int len = 0, i;
char bin[32];

for (i = 31; i >= 0; i--)
{
bin[i] = (num % 2) + '0';
num /= 2;
}
for (i = 0; i < 32; i++)
{
if (bin[i] == '1' || len > 0)
{
if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = bin[i];
len++;
}
}
if (len == 0)
{
if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = '0';
len++;
}
return (len);
}
