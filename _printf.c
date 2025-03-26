#include "main.h"
#include <stdarg.h>
#include <stddef.h>  // for NULL

/**
 * _printf - Custom printf function that handles a variety of format specifiers
 * @format: The format string containing specifiers
 * 
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char *str;
    char ch;

    if (!format)  // Check if format is NULL
        return (-1);  // Return error if format is NULL

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) == 's')  // Handle %s
        {
            str = va_arg(args, char *);
            if (str == NULL)  // Handle NULL string
            {
                count += _printf("(null)");
            }
            else
            {
                for (int i = 0; str[i] != '\0'; i++)
                    count += _putchar(str[i]);  // Print each character of the string
            }
            ptr++;  // Skip the 's'
        }
        else if (*ptr == '%' && *(ptr + 1) == 'c')  // Handle %c
        {
            ch = va_arg(args, int);  // char is promoted to int in va_arg
            count += _putchar(ch);  // Print the character
            ptr++;  // Skip the 'c'
        }
        else if (*ptr == '%' && *(ptr + 1) == '%')  // Handle %%
        {
            count += _putchar('%');
            ptr++;  // Skip the second '%'
        }
        else  // Handle regular characters
        {
            count += _putchar(*ptr);
        }
    }

    va_end(args);  // End the variable argument list

    return count;  // Return the number of characters printed
}
