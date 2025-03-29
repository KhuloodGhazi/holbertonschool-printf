#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Writes a single character to stdout.
 * @c: The character to write.
 *
 * Return: 1 on success, -1 on error.
 */
int print_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

/**
 * print_string - Writes a string to stdout.
 * @s: The string to write.
 *
 * Return: Number of characters printed, or -1 on error.
 */
int print_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		if (write(1, s, 1) != 1)
			return (-1);
		count++;
		s++;
	}
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

	if (spec == 'c')
	{
		temp = print_char((char)va_arg(args, int));
		if (temp == -1)
			return (-1);
		*printed_chars += temp;
	}
	else if (spec == 's')
	{
		temp = print_string(va_arg(args, char *));
		if (temp == -1)
			return (-1);
		*printed_chars += temp;
	}
	else if (spec == '%')
	{
		temp = print_char('%');
		if (temp == -1)
			return (-1);
		*printed_chars += temp;
	}
	else
	{
		temp = print_char('%');
		if (temp == -1)
			return (-1);
		*printed_chars += temp;
		temp = print_char(spec);
		if (temp == -1)
			return (-1);
		*printed_chars += temp;
	}
	return (0);
}

/**
 * _printf - Produces output according to a format.
 * @format: A string with text and conversion specifiers.
 *
 * Description: Supports %c, %s, and %%.
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
			if (print_char(format[i]) == -1)
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

