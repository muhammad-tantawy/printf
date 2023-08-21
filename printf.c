#include "main.h"


/**
 *print_octal - function prints octal numbers
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: the argument holder
 *Return: returns count
 */
int print_octal(char **buffer, int *index, va_list args)
{
	int i;
	unsigned int n = va_arg(args, unsigned int), count = 0;

	if (n == 0)
		(*buffer)[(*index)++] = '0', count++;
	else
		for (i = 11; i >= 0; i--)
			if ((n >> (i << 2)) & 0x7 || ((i == 0) && (n != 0)))
				(*buffer)[(*index)++] = ((n >> (i << 2)) & 0x7) + '0', count++;
	return (count);
}
/**
 *print_unsigned - function printsunsigned numbers
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: the argument holder
 *Return: returns count
 */
int print_unsigned(char **buffer, int *index, va_list args)
{
	unsigned int temp;
	unsigned int n = va_arg(args, unsigned int), count = 0;

	if (n == 0)
		(*buffer)[(*index)++] = '0', count++;
	else
		for (temp = n; temp > 9; temp /= 10)
			n *= 10;
	while (n > 9)
		(*buffer)[(*index)++] = n / 10 + '0', n %= 10, count++;
	(*buffer)[(*index)++] = n + '0', count++;
	return (count);
}

/**
 *print_hex - function prints hexadecimals
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: the argument holder
 *Return: returns count
 */
int print_hex(char **buffer, int *index, va_list args)
{
	int i;
	unsigned int n = va_arg(args, unsigned int), count = 0;
	char *hex = "0123456789abcdef";

	if (n == 0)
		(*buffer)[(*index)++] = '0', count++;
	else
		for (i = ((sizeof(n) << 3) - 4); i >= 0; i -= 4)
			if ((n >> i) & 0xf || i == ((sizeof(n) << 3) - 4))
				(*buffer)[(*index)++] = hex[(n >> i) & 0xf], count++;
	return (count);
}

/**
 *print_unknown - function prints unknown arguments passed to _printf
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@args: the argument holder
 *Return: returns 2
 */
int print_unknown(char **buffer, int *index, char c)
{
	(*buffer)[(*index)++] = '%';
	(*buffer)[(*index)++] = c;
	return (2);
}


/**
 *_printf - function mimics printf
 *@format: variable holds the format specifier
 *Return: returns number of charcaters printed
 */
int _printf(const char *format, ...)
{
	specifier_t specifiers[] = {{'c', print_char}, {'s', print_string},
	{'%', print_percent}, {'d', print_int}, {'i', print_int},
	{'p', print_address}, {'o', print_octal},
	{'u', print_unsigned}, {'x', print_hex}, {'X', print_hex}, {0, NULL}};
	int buffer_size = 1024, index = 0, count = 0, i = 0, j = 0, found = 0;
	char *new_buffer, *buffer;
	va_list args;

	va_start(args, format);
	buffer = malloc(buffer_size);
	if (!buffer)
		return (-1);
	for (i = 0; format[i]; i++)
		if (format[i] == '%')
		{
			i++, found = 0;
			for (j = 0; specifiers[j].c; j++)
				if (format[i] == specifiers[j].c)
				{
					count += specifiers[j].f(&buffer, &index, args);
					found = 1, break;
				}
			if (!found)
				count += print_unknown(&buffer, &index, format[i]);
		}
				else
					buffer[index++] = format[i], count++;
				if (index >= buffer_size - 1)
				{
					new_buffer = realloc(buffer, buffer_size *= 2);
					if (new_buffer)
						buffer = new_buffer;
					else
					{
						free(buffer);
						return (-1);
					}
				}
	write(1, buffer, index), free(buffer), va_end(args);
	return (count);
}
