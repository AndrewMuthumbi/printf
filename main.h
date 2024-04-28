#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void print_char(char c, int *count);
void print_string(char *str, int *count);
void print_percent(int *count);

#endif /* MAIN_H */
