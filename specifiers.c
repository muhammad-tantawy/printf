#include "main.h"

/**
 *print_char - function prints characters
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: arguments of the vriadic function
 *Return: returns 1
 */
int print_char(char **buffer, int *index, va_list args)
{
	(*buffer)[(*index)++] = va_arg(args, int);
	return (1);
}
/**
 *print_string - function prints string
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: arguments of the vriadic function
 *Return: returns counts of int
 */
int print_string(char **buffer, int *index, va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		(*buffer)[(*index)++] = str[i];
		count++;
	}
	return (count);
}
/**
 *print_percent - function prints percentage
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: the argument holder
 *Return: returns 1
 */
int print_percent(char **buffer, int *index, va_list args)
{
	(void)args;
	(*buffer)[(*index)++] = '%';
	return (1);
}

/**
 *print_int - function prints integers
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: the argument holder
 *Return: returns count
 */
int print_int(char **buffer, int *index, va_list args)
{
	int n;
	int count = 0;
	int temp, size;

	n = va_arg(args, int);
	if (n < 0)
		(*buffer)[(*index)++] = '-', n = -n, count++;
	if (n == 0)
		(*buffer)[(*index)++] = '0', count++;
	else
	{
		temp = n, size = 1;
		while (temp /= 10)
		size *= 10;
		while (size > 0)
			(*buffer)[(*index)++] = n / size + '0', n %= size, size /= 10, count++;
	}
	return (count);
}
/**
 *print_address - function prints hexadecimal address
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: the argument holder
 *Return: returns count
 */
int print_address(char **buffer, int *index, va_list args)
{
	unsigned long n = (unsigned long)va_arg(args, void *);
	char *hex = "0123456789abcdef";
	int count = 0, i = 0;

	(*buffer)[(*index)++] = '0', (*buffer)[(*index)++] = 'x', count += 2;
	for (i = (sizeof(n) << 3) - 4; i >= 0; i -= 4)
		(*buffer)[(*index)++] = hex[(n >> i) & 0xf], count++;
	return (count);
}

