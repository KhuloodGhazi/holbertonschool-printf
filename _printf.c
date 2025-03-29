#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string composed of zero or more directives.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
    {
        return (-1); /* Correctly formatted return statement */
    }

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += print_char(args);
                    break;
                default:
                    write(1, &format[i - 1], 1);
                    write(1, &format[i], 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}
