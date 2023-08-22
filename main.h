#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int print_char(char **buffer, int *index, va_list args);
int _printf(const char *format, ...);
int print_string(char **buffer, int *index, va_list args);
int print_percent(char **buffer, int *index, va_list args);
int print_int(char **buffer, int *index, va_list args);
int print_address(char **buffer, int *index, va_list args);
int print_octal(char **buffer, int *index, va_list args);
int print_unsigned(char **buffer, int *index, va_list args);
int print_hex(char **buffer, int *index, va_list args);
int print_unknown(char **buffer, int *index, char c);

typedef struct specifier

{
	char c;
	int (*f)(char **, int *, va_list);
} specifier_t;
#endif
