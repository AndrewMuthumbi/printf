#include "main.h"

/**
 * print_hex - Prints an unsigned int in hexadecimal (lowercase) to the buffer
 * @num: Unsigned int to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int print_hex(unsigned int num, char *buffer, int *buf_index)
{
int count = 0;
char hex_digits[] = "0123456789abcdef";

if (num / 16)
count += print_hex(num / 16, buffer, buf_index);

if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = hex_digits[num % 16];
count++;

return count;
}
