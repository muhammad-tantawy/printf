#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int print_char(char **buffer, int *index, va_list args);
int _printf(const char *format, ...);
int print_string(char **buffer, int *index, va_list args);
int print_percent(char **buffer, int *index, va_list args);
int print_int(char **buffer, int *index, va_list args);
int print_address(char **buffer, int *index, va_list args);
int print_octal(char **buffer, int *index, va_list args);
int print_unsigned(char **buffer, int *index, va_list args);
int print_hex(char **buffer, int *index, va_list args);
int print_unknown(char **buffer,int *index,char c);
#define CHECK_BUFFER() if (index >= buffer_size - 1) { new_buffer = realloc(buffer, buffer_size *= 2); if (new_buffer) buffer = new_buffer; else { free(buffer); return (-1); } }
typedef struct specifier

{
    char c;
    int (*f)(char **, int *, va_list);
} specifier_t;
#endif
