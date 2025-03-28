/**
 * print_string - Prints a string
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)"; /* Handle NULL string */

	while (*str)
		count += write(1, str++, 1);

	return (count);
}

/**
 * print_number - Prints an integer
 * @n: Number to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	char buffer[12]; /* Max size for int (-2147483648) */
	int i = 0, count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
		num = n;

	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num);

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
