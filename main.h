#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(unsigned int num);
int print_binary(va_list args);
int handle_specifier(const char *format, va_list args, int *count);

#endif /* MAIN_H */
