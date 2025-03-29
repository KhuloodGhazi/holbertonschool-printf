#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: A string that contains the text to be written and the
 *          conversion specifiers.
 *
 * Description: This function prints formatted output to stdout.
 * It supports the conversion specifiers: %c, %s, and %%.
 * Unsupported specifiers are printed as if the percent sign is literal.
 * If format is NULL or a lone '%' is encountered at the end,
 * the function returns -1.
 *
 * Return: The number of characters printed (excluding the null byte)
 *         on success, or -1 on error.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, printed_chars;
    char ch;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(args, format);
    printed_chars = 0;
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
            if (format[i] == 'c')
            {
                ch = (char)va_arg(args, int);
                if (write(1, &ch, 1) != 1)
                {
                    va_end(args);
                    return (-1);
                }
                printed_chars++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    if (write(1, str, 1) != 1)
                    {
                        va_end(args);
                        return (-1);
                    }
                    printed_chars++;
                    str++;
                }
            }
            else if (format[i] == '%')
            {
                if (write(1, "%", 1) != 1)
                {
                    va_end(args);
                    return (-1);
                }
                printed_chars++;
            }
            else
            {
                /* Unsupported specifier: print the '%' and then the char */
                if (write(1, "%", 1) != 1)
                {
                    va_end(args);
                    return (-1);
                }
                printed_chars++;
                if (write(1, &format[i], 1) != 1)
                {
                    va_end(args);
                    return (-1);
                }
                printed_chars++;
            }
        }
        else
        {
            if (write(1, &format[i], 1) != 1)
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
