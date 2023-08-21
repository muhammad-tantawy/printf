#ifndef MAIN_H
#define MAIN_H

int print_char(char **buffer, int *index, va_list args);
int _printf(const char *format, ...);
int print_string(char **buffer, int *index, va_list args);
int print_percent(char **buffer, int *index);
#endif
