#include "main.h"

/**
 * print_string - Prints a string to the buffer
 * @args: Va_list containing the string to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int print_string(va_list args, char *buffer, int *buf_index)
{
char *str = va_arg(args, char *);
int len = 0;

if (str == NULL)
str = "(null)";

while (str[len])
{
if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = str[len];
len++;
}

return (len);
}
