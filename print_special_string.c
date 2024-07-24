#include "main.h"

/**
 * print_special_string - Prints a string and converts non-printable characters
 * @args: Va_list containing the string to print
 * @buffer: Buffer to accumulate characters
 * @buf_index: Index of the buffer
 *
 * Return: Number of characters printed
 */
int print_special_string(va_list args, char *buffer, int *buf_index)
{
char *str = va_arg(args, char *);
int len = 0;
char hex[3];

if (str == NULL)
str = "(null)";

while (str[len])
{
if ((str[len] > 0 && str[len] < 32) || str[len] >= 127)
{
if (*buf_index + 4 >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);
*buf_index = 0;
}
buffer[(*buf_index)++] = '\\';
buffer[(*buf_index)++] = 'x';
hex[0] = (str[len] / 16) < 10 ? (str[len] / 16) + '0' : (str[len] / 16) - 10 + 'A';
hex[1] = (str[len] % 16) < 10 ? (str[len] % 16) + '0' : (str[len] % 16) - 10 + 'A';
hex[2] = '\0';
buffer[(*buf_index)++] = hex[0];
buffer[(*buf_index)++] = hex[1];
}
else
{
if (*buf_index >= BUFFER_SIZE)
{
write(1, buffer, *buf_index);

*buf_index = 0;
 }

buffer[(*buf_index)++] = str[len];
}
len++;
}

return (len);
}
