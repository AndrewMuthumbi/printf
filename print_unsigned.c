#include "main.h"

/**
 * print_unsigned - Prints an unsigned int to the buffer
 * @num: Unsigned int to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int num, char *buffer, int *buf_index)
{
int count = 0;

if (num / 10)
count += print_unsigned(num / 10, buffer, buf_index);

if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = (num % 10) + '0';
count++;

return count;
}
