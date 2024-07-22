# Custom Printf Function

This project implements a custom `_printf` function that mimics the behavior of the standard C `printf` function. The function supports the following conversion specifiers:

- `%c`: Print a single character
- `%s`: Print a string
- `%%`: Print a percent sign

## Files

- `main.h`: Header file containing function prototypes and necessary includes
- `_printf.c`: Main implementation of the `_printf` function
- `print_functions.c`: Helper functions for printing characters and strings

## Compilation

Compile the project using the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

## Usage

Include the `main.h` header in your C file and use the `_printf`
function as you would use the standard `printf` function.

Example:

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "world");
    _printf("Character: %c\n", 'A');
    _printf("Percent sign: %%\n");
    return (0);
}
```

## Limitations

This implementation does not support:
- Buffer handling
- Flag characters
- Field width
- Precision
- Length modifiers

## Authors

[ANDREW MUNGAI]