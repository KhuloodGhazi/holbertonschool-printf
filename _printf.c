#include <stdarg.h>
#include <stdio.h>

int print_integer(int num)
{
	/* Function to print an integer */
	return (printf("%d", num));
}

int print_string(char *str)
{
	/* Function to print a string */
	return (printf("%s", str));
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
			format++;

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

