#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

/* Function prototypes for print functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/**
 * struct print - Struct for print functions
 * @spec: The conversion specifier
 * @f: The function associated
 */
typedef struct print
{
char spec;
int (*f)(va_list);
} print_t;

#endif /* MAIN_H */
