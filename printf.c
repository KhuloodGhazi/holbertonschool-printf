#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: On success 1, -1 on error
 */
int _putchar(char c)
{
return write(1, &c, 1);
}

/**
 * _printf - produces output according to a format
 * @format: format string with specifiers
 * @...: variable arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
{
format++;
if (*format == 'c')
{
char c = (char)va_arg(args, int);
count += _putchar(c);
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
while (*str)
{
count += _putchar(*str++);
}
}
else if (*format == '%')
{
count += _putchar('%');
}
}
else
{
count += _putchar(*format);
}
format++;
}
va_end(args);
return count;
}
