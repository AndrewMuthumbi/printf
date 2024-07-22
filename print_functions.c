#include "main.h"

int print_char(char c)
{
return write(1, &c, 1);
}

int print_string(char *str)
{
int count = 0;

if (str == NULL)
str = "(null)";

while (*str)
{
count += print_char(*str);
str++;
}

return count;
}
