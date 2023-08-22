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
	int i = 0;
	unsigned int n = va_arg(args, unsigned int), count = 0;
	char octal[11];

	if (n == 0)
		(*buffer)[(*index)++] = '0', count++;
	else
	{
		while (n > 0)
		{
			octal[i++] = (n % 8) + '0';
			n /= 8;
		}
		while (--i >= 0)
			(*buffer)[(*index)++] = octal[i], count++;
	}
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
	unsigned int n = va_arg(args, unsigned int), count = 0;
	char temp[10];
	int i = 0;

	if (n == 0)
		(*buffer)[(*index)++] = '0', count++;
	else
	{
		while (n > 0)
		{
			temp[i++] = (n % 10) + '0';
			n /= 10;
		}
	while (--i >= 0)
		(*buffer)[(*index)++] = temp[i], count++;
	}
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
	unsigned int n = va_arg(args, unsigned int), count = 0;
	char hex[9];
	int i = 0;

	if (n == 0)
		(*buffer)[(*index)++] = '0', count++;
	else
	{
		while (n > 0)
		{
			hex[i++] = "0123456789abcdef"[n % 16];
			n /= 16;
		}
	while (--i >= 0)
		(*buffer)[(*index)++] = hex[i], count++;
	}
	return (count);
}

/**
 *print_unknown - function prints unknown arguments passed to _printf
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@c: character to check
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
	{'p', print_address}, {'o', print_octal}, {'u', print_unsigned},
	{'x', print_hex}, {'X', print_hex}, {0, NULL}};
	int buffer_size = 1024, index = 0, count = 0, i = 0, j = 0, found = 0;
	char *new_buffer, *buffer;
	va_list args;

	va_start(args, format), buffer = malloc(buffer_size);
	if (!buffer || !format)
		return (-1);
	for (i = 0; format[i]; i++)
	if (format[i] == '%')
	{
		i++, found = 0;
	for (j = 0; specifiers[j].c; j++)
		if (format[i] == specifiers[j].c)
		{
			count += specifiers[j].f(&buffer, &index, args), found = 1;
			break;
		}
	if (!found)
		count += print_unknown(&buffer, &index, format[i]);
	}
	else
		buffer[index++] = format[i], count++;
	
	switch (format[++i])
	{
		case 'd':
		case 'i':
		count += print_int(&buffer, &index, args);
		break;

	}
	
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
