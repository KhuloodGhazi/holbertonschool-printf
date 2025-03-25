#include <stdarg.h>
#include <stdio.h>

int print_integer(int num)
{
    return (printf("%d", num));
}

int print_string(char *str)
{
    return (printf("%s", str));
}

int print_char(char c)
{
    return (putchar(c));
}

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;  // Move past '%'

            if (*format == 'd')
            {
                int num = va_arg(args, int);
                count += print_integer(num);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char*);
                count += print_string(str);
            }
            else if (*format == 'c')
            {
                char c = (char) va_arg(args, int);  // Handle char as an int
                count += print_char(c);
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }
            else
            {
                // Handle invalid format specifiers by doing nothing or printing an error
                putchar('%');
                putchar(*format);
                count += 2;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}

