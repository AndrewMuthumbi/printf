#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);
int handle_unknown(char format);

#endif /* MAIN_H */
