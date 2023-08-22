#include "main.h"

/**
 * print_int - prints an integer
 * @args: argument list
 * Return: the number of characters printed
 */
int print_int(va_list args)
{
	int count = 0;
	long int n = va_arg(args, int);
	long int temp, size;

	if (n < 0)
		_putchar('-'), n = -n, count++;
	if (n == 0)
		_putchar('0'), count++;
	else
	{
		temp = n, size = 1;
		while (temp /= 10)
			size *= 10;
		while (size > 0)
			_putchar(n / size + '0'), n %= size, size /= 10, count++;
	}
	return (count);
}
