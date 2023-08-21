#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int print_char(char **buffer, int *index, va_list args)
{
(*buffer)[(*index)++] = va_arg(args, int);
return (1);
}

int print_string(char **buffer, int *index, va_list args)
{
char *str = va_arg(args, char *);
int count = 0;
for (int i = 0; str[i] != '\0'; i++)
{
(*buffer)[(*index)++] = str[i];
count++;
}
return (count);
}

int print_percent(char **buffer, int *index)
{
(*buffer)[(*index)++] = '%';
return (1);
}

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int buffer_size = 1024;
char *buffer = malloc(buffer_size);
if (!buffer)
return (-1);
int index = 0;
int count = 0;
for (int i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += print_char(&buffer, &index, args);
break;
case 's':
count += print_string(&buffer, &index, args);
break;
case '%':
count += print_percent(&buffer, &index);
break;
default:
break;
}
}
else
{
buffer[index++] = format[i];
count++;
}
if (index >= buffer_size - 1)
{
buffer_size *= 2;
char *new_buffer = realloc(buffer, buffer_size);
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
