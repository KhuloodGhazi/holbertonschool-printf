#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* Function declarations */
int _putchar(char c);
int print_string(const char *s);
int print_number(int n);
int handle_specifier(char spec, va_list args, int *printed_chars);
int _printf(const char *format, ...);

/**
* _putchar - Writes a character to standard output.
* @c: The character to print.
*
* Return: 1 on success, -1 on error.
*/
int _putchar(char c)
{
if (write(1, &c, 1) != 1)
return (-1);
return (1);
}

/**
* print_string - Prints a string to standard output.
* @s: The string to print.
*
* Return: The number of characters printed.
*/
int print_string(const char *s)
{
int count = 0;

while (*s)
{
if (_putchar(*s) != 1)
return (-1);
count++;
s++;
}
return (count);
}

/**
* print_number - Converts an integer to string and prints it.
* @n: The integer to print.
*
* Return: The number of characters printed.
*/
int print_number(int n)
{
int count = 0;

if (n == INT_MIN) /* Special case for INT_MIN */
{
count += _putchar('-');
count += _putchar('2');
n = 147483648; /* Change to 2147483648 - 1 */
}
else if (n < 0)
{
count += _putchar('-');
n = -n; /* Make n positive */
}

/* Recursively print each digit */
if (n / 10)
count += print_number(n / 10);

count += _putchar(n % 10 + '0');
return (count);
}

/**
* handle_specifier - Processes format specifiers for _printf.
* @spec: The specifier character.
* @args: The list of arguments.
* @printed_chars: Pointer to total printed count.
*
* Return: 0 on success, -1 on error.
*/
int handle_specifier(char spec, va_list args, int *printed_chars)
{
int temp;

if (spec == 'c') /* Handle character */
{
temp = _putchar((char)va_arg(args, int));
if (temp == -1)
return (-1);
*printed_chars += temp;
}
else if (spec == 's') /* Handle string */
{
char *str = va_arg(args, char *);
if (print_string(str) == -1)
return (-1);
*printed_chars += print_string(str);
}
else if (spec == '%') /* Handle percent sign */
{
*printed_chars += _putchar('%');
}
else if (spec == 'd' || spec == 'i') /* Handle integer */
{
int num = va_arg(args, int);
*printed_chars += print_number(num);
}
else /* Handle unknown specifier */
{
*printed_chars += _putchar('%');
*printed_chars += _putchar(spec);
}
return (0);
}

/**
* _printf - Produces output according to a format.
* @format: A string with text and conversion specifiers.
*
* Description: Supports %c, %s, %d, %i, and %%.
* Unsupported specifiers print the percent sign and the specifier.
* Returns -1 if format is NULL or a lone '%' appears at the end.
*
* Return: Number of characters printed, or -1 on error.
*/
int _printf(const char *format, ...)
{
va_list args;
int i, printed_chars = 0;

if (format == NULL)
return (-1);

va_start(args, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
{
va_end(args);
return (-1);
}
if (handle_specifier(format[i], args, &printed_chars) == -1)
{
va_end(args);
return (-1);
}
}
else
{
if (_putchar(format[i]) == -1)
{
va_end(args);
return (-1);
}
printed_chars++;
}
}

va_end(args);
return (printed_chars);
}
