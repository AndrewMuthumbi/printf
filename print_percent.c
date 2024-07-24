#include "main.h"

/**
 * print_percent - Prints a percent sign to the buffer
 * @args: Va_list (unused)
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed (always 1)
 */
int print_percent(va_list args, char *buffer, int *buf_index)
{
(void)args;

if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = '%';
return (1);
}
