#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *print_char - 
 *
 */
int print_char(va_list args)
{
return (write(1, &va_arg(args, int), 1));
}

/**
 *print_string - 
 *
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;
for (int i = 0; str[i] != '\0'; i++)
count += write(1, &str[i], 1);
return (count);
}


/**
 * print_percent - 
 *
 */

int print_percent(void)
{
return (write(1, "%", 1));
}
/**
 *_printf - 
 *
 *
 *
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
for (int i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
count += print_percent();
break;
default:
break;
}
}
else
count = count + write(1, &format[i], 1);
}
va_end(args);
return (count);
}

