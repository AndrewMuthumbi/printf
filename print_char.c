#include "main.h"

/**
 * print_char - Prints a single character to the buffer
 * @args: Va_list containing the character to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args, char *buffer, int *buf_index)
{
if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = (char)va_arg(args, int);
return (1);
}
