#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character
 * @args: argument list
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: argument list
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	int count = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: argument list
 * Return: the number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;

	_putchar('%');
	return (1);
}

/**
 * print_unknown - prints an unknown specifier
 * @format: format string
 * Return: the number of characters printed
 */
int print_unknown(const char **format)
{
	int count = 0;

	_putchar('%');
	if (**format != '\0')
		_putchar(**format);
	else
		(*format)--;
	count += 2;
	return (count);
}
