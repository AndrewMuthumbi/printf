#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * rot13 - Encodes a string using ROT13 substitution cipher
 * @str: The string to encode
 *
 * Return: Pointer to the encoded string
 */
char *rot13(char *str)
{
    char *ptr = str;
    while (*str)
    {
        if ((*str >= 'a' && *str <= 'm') || (*str >= 'A' && *str <= 'M'))
            *str += 13;
        else if ((*str >= 'n' && *str <= 'z') || (*str >= 'N' && *str <= 'Z'))
            *str -= 13;
        str++;
    }
    return (ptr);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buffer_index = 0;
    int count = 0;
    const char *null_str; /* Declaration of null_str */

    va_start(args, format);

    while (*format)
    {
        int len; /* Initialize len variable */
        int precision = -1; /* No precision by default */
        char num_buffer[32]; /* Max integer digits */

        if (*format != '%')
        {
            /* Add non-format characters directly to buffer */
            buffer[buffer_index++] = *format;
            count++;
        }
        else
        {
            /* Handle format specifier */
            format++;
            if (*format == 'c')
            {
                /* Character argument */
                char c = (char)va_arg(args, int);
                buffer[buffer_index++] = c;
                count++;
            }
            else if (*format == 's')
            {
                /*string argument */
                char *str = va_arg(args, char *);
                while (*(format + 1) >= '0' && *(format + 1) <= '9')
                {
                    precision = precision == -1 ? 0 : precision * 10;
                    precision += (*(format + 1) - '0');
                    format++;
                }
                if (str)
                {
                    len = 0;
                    int i = 0;
                    while (str[i] && (precision == -1 || i < precision))
                    {
                        buffer[buffer_index++] = str[i];
                        count++;
                        i++;
                    }
                }
                else
                {
                    /* If NULL string is passed, add "(null)" to buffer */
                    null_str = "(null)"; /* Initialization of null_str */
                    while (*null_str && (precision == -1 || count < precision))
                    {
                        buffer[buffer_index++] = *null_str;
                        null_str++;
                        count++;
                    }
                }
            }
            else if (*format == '%')
            {
                /* Add '%' character directly to buffer */
                buffer[buffer_index++] = '%';
                count++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                /* Integer argument */
                int num = va_arg(args, int);
                if (num < 0)
                {
                    num_buffer[len++] = '-';
                    num *= -1;
                }
                do
                {
                    num_buffer[len++] = '0' + (num % 10);
                    num /= 10;
                } while (num != 0);

                /* Add digits to buffer in reverse order */
                while (len > 0)
                {
                    len--;
                    buffer[buffer_index++] = num_buffer[len];
                    count++;
                }
            }
            else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
            {
                /* Unsigned integer argument */
                unsigned int num = va_arg(args, unsigned int);
                do
                {
                    int digit = *format == 'o' ? (num & 7) : (num & 0xF);
                    num_buffer[len++] = digit < 10 ? '0' + digit : (*format == 'x' ? 'a' : 'A') + (digit - 10);
                    num >>= *format == 'o' ? 3 : 4;
                } while (num != 0);

                /* Add digits to buffer in reverse order */
                while (len > 0)
                {
                    len--;
                    buffer[buffer_index++] = num_buffer[len];
                    count++;
                }
            }
            else if (*format == 'R')
            {
                /* ROT13 string argument */
                char *str = va_arg(args, char *);
                if (str)
                {
                    str = rot13(str);
                    int i = 0;
                    while (str[i])
                    {
                        buffer[buffer_index++] = str[i];
                        count++;
                        i++;
                    }
                }
                else
                {
                    /*NULL string is passed, add "(null)" to buffer */
                    null_str = "(null)"; /* Initialization of null_str */
                    while (*null_str)
                    {
                        buffer[buffer_index++] = *null_str;
                        null_str++;
                        count++;
                    }
                }
            }
            else
            {
                /* Invalid format specifier, print as is */
                buffer[buffer_index++] = '%';
                buffer[buffer_index++] = *format;
                count += 2;
            }
        }

        /* Check if buffer is full, then write it to stdout */
        if (buffer_index >= (int)(sizeof(buffer) - 1))
        {
            write(1, buffer, buffer_index);
            buffer_index = 0;
        }

        format++;
    }

    /* Write remaining buffer to stdout */
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
    }

    va_end(args);

    return (count);
}
