#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_specifier - Handles format specifiers
 * @specifier: The format specifier character
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')
	{
		count += print_char(va_arg(args, int));
	}
	else if (specifier == 's')
	{
		count += print_string(va_arg(args, char *));
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		count += print_number(va_arg(args, int));
	}
	else
	{
		count += write(1, "%", 1); /* Print % */
		count += write(1, &specifier, 1); /* Print unknown specifier */
	}

	return (count);
}
