#include "main.h"

/**
 * calc_width - handle printing width
 * @format: string arg format
 * @a: selected args list
 * @list: all args list
 * Return: width (Success)
 */
int calc_width(const char *format, int *a, va_list list)
{
	int curr_a;
	int width = 0;

	for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
	{
		if (is_digit(fmt[curr_a]))
		{
			width *= 10;
			width += format[curr_a] - '0';
		}
		else if (fmt[curr_a] == '*')
		{
			curr_a++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = curr_a - 1;

	return (width);
}