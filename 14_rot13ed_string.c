#include "main.h"

/**
 * rot13 - print rot13
 * @rot: list passed
 * Return: chars count
 */
void rot13(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			char base = (*str >= 'a') ? 'a' : 'A';

			*str = (*str - base + 13) % 26 + base;
		}
		str++;
	}
}

/**
 * custom_printf - print formated string
 */
int custom_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'R')
		{
			format += 2;

			char *str = va_arg(args, char*);

			rot13(str);
			printf("%s", str);
		}
		else
		{
			printf("%c", *format);
			format++;
		}
	}

	va_end(args);
	return 0;
}

/**
 * custom_printf - print formatted string
 */
int main()
{
	char message[] = "Hello, World!";

	custom_printf("Original: %s\n", message);
	custom_printf("ROT13: %R\n", message);

	return 0;
}
