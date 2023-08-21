#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int print_char(char **buffer, int *index, va_list args);
int _printf(const char *format, ...);
int print_string(char **buffer, int *index, va_list args);
int print_percent(char **buffer, int *index, va_list args);

typedef struct specifier
{
    char c;
    int (*f)(char **, int *, va_list);
} specifier_t;
#endif
