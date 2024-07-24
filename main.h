#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>  /* For write function */
#include <stddef.h>  /* For NULL */

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int handle_specifier(const char *format, va_list args, char *buffer, int *buf_index);
int print_char(va_list args, char *buffer, int *buf_index);
int print_string(va_list args, char *buffer, int *buf_index);
int print_percent(va_list args, char *buffer, int *buf_index);
int print_int(va_list args, char *buffer, int *buf_index);
int print_unsigned(unsigned int num, char *buffer, int *buf_index);
int print_octal(unsigned int num, char *buffer, int *buf_index);
int print_hex(unsigned int num, char *buffer, int *buf_index);
int print_hex_upper(unsigned int num, char *buffer, int *buf_index);
int print_binary(va_list args, char *buffer, int *buf_index);
int print_special_string(va_list args, char *buffer, int *buf_index);

#endif /* MAIN_H */
