#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_string(const char *s);
int print_number(int n);
int handle_specifier(char spec, va_list args, int *printed_chars);

#endif /* MAIN_H */
