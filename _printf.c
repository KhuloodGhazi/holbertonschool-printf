#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function that handles %c, %s, and %%
 * @format: Format string containing directives
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')  /* Handle format specifiers */
        {
            format++;
            if (*format == 'c')  /* Character */
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's')  /* String */
            {
                char *str = va_arg(args, char *);
                int len = 0;

                if (str == NULL)
                    str = "(null)";

                while (str[len])
                    len++;

                write(1, str, len);
                count += len;
            }
            else if (*format == '%')  /* Percent sign */
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}
