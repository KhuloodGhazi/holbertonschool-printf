#include "main.h"

/**
 * print_char - Prints a single character
 * @c: The character to print
 * Return: Number of characters printed
 */
int print_char(char c)
{
	_putchar(c);
	return (1);
}

/**
 * print_string - Prints a string
 * @str: The string to print
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * print_percent - Prints a percent sign
 * Return: Always 1
 */
int print_percent(void)
{
	_putchar('%');
	return (1);
}
