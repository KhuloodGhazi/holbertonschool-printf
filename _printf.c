#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Custom printf function
* @format: Format string
*
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (!format)
return (-1); /* Return -1 if format is NULL */

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0') /* Handle single % case */
return (-1);  /* Return error like standard printf */
if (*format == '%')
count += write(1, "%", 1); /* Print a single % */
else
{
/* Handle other format specifiers like %c, %s, %d */
count += handle_specifier(*format, args);
}
}
else
{
count += write(1, format, 1); /* Print normal characters */
}
format++;
}

va_end(args);
return (count);
}

