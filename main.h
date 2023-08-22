#ifndef MA_H
#define MA_H
#include <stdarg.h>
#include <unistd.h>
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_unknown(const char **format);
int _printf(const char *format, ...);

#endif
