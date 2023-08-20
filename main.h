#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)
#define S_SHORT 1
#define S_LONG 2
#define FUNC_SPACE 16
#define FUNC_MINUS 1
#define FUNC_ZERO 4
#define FUNC_PLUS 2
#define FUNC_HASH 8

/**
 * struct format - struct operator
 * @format: fn format
 * @fn: function used at instance
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format format_t - struct operator
 * @format: format
 * @format_t: function used in instance
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *a, va_list list, char buffer[],
		int flags, int width, precesion, int size);
/* Function Handlers */
int calc_flags(const char *format, int *a);
int calc_width(const char *format, int *a, va_list list);
int calc_precision(const char *format, int *a, va_list list);
int calc_size(const char *format, int *a);
int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);
/* width */
int write_num(int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);
int handle_write_char(char c, char buffer[],
		int flags, int width, precision, int size);
int write_number(int is_positive, int ind, cha buffer[],
		int flags, int width, int precision, int size);
/* Chars and Strings Specifiers */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
		int flags, int width, precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffere[],
		int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
/* Numbers */
int print_unsigned(va_list types, char [],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
/* Convert */
int is_printable(char);
int is_digit(char);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsignged long int num, int size);

#endif /* end of MAIN_H */
