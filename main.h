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
 * struct fmt - struct operator
 * @format: fn format
 * @fn: function used at instance
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct operator
 * @fmt: fm_t format
 * @fm_t: function used in instance
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *a,
		va_list list, char buffer[], int flags, int width, precesion, int size);

/* Function Specifier Handlers */
int calc_flags(const char *format, int *a);
int calc_width(const char *format, int *a, va_list list);
int calc_precision(const char *format, int *a, va_list list);
int calc_size(const char *format, int *a);
/* Chars and Strings Specifiers */
int print_percent(va_list types, char buffer [],
		int flags, int width, int percision, int size);
int print_string(va_list types, char buffer [],
		int flags, int width, int percision, int size);
int print_char(va_list types, char buffer [],
		int flags, int width, int percision, int size);

#endif /* end of MAIN_H */
