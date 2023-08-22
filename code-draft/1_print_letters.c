#include "main.h"

void _print_letters(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd' || *format == 'i')
			{
				int value = va_arg(args, int);
				printf("%d", value);
			}
			else
			{
				putchar('%');

				if (*format != '\0')
				{
					putchar(*format);
				}
			}
		}
		else
		{
			putchar(*format);
		}

		format++;
	}

	va_end(args);
}
