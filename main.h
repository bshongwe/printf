#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/* Buffer Defs */
/*#define UNUSED(x) (void)(x)*/
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
/*
int custom_printf(const char *format, ...);
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
*/
int (*check_prtr(char specifier))(char *, int, va_list);

/* Integers */
char *_lcutoa(unsigned int value, unsigned int based);
int _abs(int n);
char *_utoa(unsigned int value, unsigned int based);
char *_itoa(int value, int base);

/* Assign and count len to buffer */
int _rev_assign(char *buff, int count, char *value);
int _assign(char *buff, int count, char *value);

/* Parameters */
int func_d(char *buff, int count, va_list value);
int func_i(char *buff, int count, va_list value);
int func_u(char *buff, int count, va_list value);
int func_o(char *buff, int count, va_list value);
int func_x(char *buff, int count, va_list value);
int func_X(char *buff, int count, va_list value);
int func_c(char *buff, int count, va_list value);
int func_s(char *buff, int count, va_list value);
int func_ptg(char *buff, int count, va_list value);
int func_b(char *buff, int count, va_list value);
int func_r(char *buff, int count, va_list value);
int func_R(char *buff, int count, va_list value);

/* Strings */
int _strlen(char *s);
char *_rot13(char *str);
char *_reverse(char *s, int n);
void _rev_ptr(char *str);
void _strcpy(char *dest, char *src);

#endif /* end of MAIN_H */
