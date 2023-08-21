#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/* Buffer Defs */
#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* Structs*/
/**
 * struct ptr - struct for params and funcs
 * @c: indicator param
 * @f: func param
*/
typedef struct ptr
{
	char *c;
	int (*f)(char *, int, va_list);
} ptr_ch;

/* Func Prototypes */
int _printf(const char *format, ...);
void _print_letters(const char *format, ...);
void printBinary(unsigned int num);
void printInteger(unsigned int num, char specifier);
char buffer[BUFFER_SIZE];
void printFormattedString(const char *str);
void print_memory_address(const void *ptr);
void handle_length_modifiers(char modifier, char specifier, va_list args);
void _printf_width(const char *format, ...);
void _precision(const char *format, ...);
void formatWithFlags(const char *format, ...);
int handle_format_specifier(const char **format, va_list *args);


#endif /* end of MAIN_H */
