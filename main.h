#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int print_char(char c);
int print_string(char *str);
int print_percent(void);
int _printf(const char *format, ...);

#endif /* MAIN_H */
