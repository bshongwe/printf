#include "main.h"

/**
 * _printf - func print
 * @format: input str char
 * Return: number of char, count (Success)
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;
			count += handle_format_specifier(&format, &args);
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}

/**
 * handle_format_specifier - print char count in specifier format
 * @args: logic implement for cases
 * @format: update format pointer
 * Return: number of char printed (Success)
 */
int handle_format_specifier(const char **format, va_list *args)
{
	int count = 0;

	switch (**format)
	{
		case 'c': {
				  char c = (char)va_arg(*args, int);

				  putchar(c);
				  count++;
				  break;
			  }
		case 's': {
				  char *str = va_arg(*args, char *);

				  while (*str != '\0')
				  {
					  putchar(*str);
					  str++;
					  count++;
				  }
				  break;
			  }
		case '%': {
				  putchar('%');
				  putchar(**format);
				  count += 2;
				  break;
			  }
	}

	(*format)++;
	return (count);
}
