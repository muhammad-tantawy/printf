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
 *_printf - function mimics printf
 *@format: variable holds the format specifier
 *Return: returns number of charcaters printed
 */
int _printf(const char *format, ...)
{
	specifier_t specifiers[] = {{'c', print_char}, {'s', print_string},
					{'%', print_percent}, {0, NULL}};
	int i, j, count, index = 0, buffer_size = 1024;
	char *new_buffer, *buffer;
	va_list args;

	va_start(args, format);
	buffer = malloc(buffer_size);
	if (!buffer)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; specifiers[j].c != 0; j++)
				if (format[i] == specifiers[j].c)
					count += specifiers[j].f(&buffer, &index, args);
		}
		else
		{
			buffer[index++] = format[i];
			count++;
		}
		if (index >= buffer_size - 1)
		{
			buffer_size *= 2;
			new_buffer = realloc(buffer, buffer_size);
			if (!new_buffer)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_buffer;
		}
	}
	write(1, buffer, index);
	free(buffer);
	va_end(args);
	return (count);
}
