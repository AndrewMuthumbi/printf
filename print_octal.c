#include "main.h"

/**
 * print_octal - Prints an unsigned int in octal to the buffer
 * @num: Unsigned int to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int num, char *buffer, int *buf_index)
{
int count = 0;

if (num / 8)
count += print_octal(num / 8, buffer, buf_index);

if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
 }

buffer[(*buf_index)++] = (num % 8) + '0';
count++;

return count;
}
