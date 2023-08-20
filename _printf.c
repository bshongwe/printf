#include " main.h"

void print_buffer(char buffer[], int *buffer_ind);

/**
 * _printf - print according to format
 * @format: char str input directives
 * @...: variable n params
 * Return: chars printed according to format
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_ind = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (fomat == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_ind++] = format[a];
			if (buffer_ind == BUFFER_SIZE)
				print_buffer(buffer, &buffer_ind);
			{
				printed_chars++;
			}
		}
		else
		{
			print_buffer(buffer, &buffer_ind);
			flags = calc_flags(format, &a);
			width = calc_width(format, &a, list);
			precision = calc_precision(format, &a, list);
			size = calc_size(format, &a);
			a++;
			printed = handle_print(format, &a, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffer_a);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - check and return buffer chars
 * @buffer: input chars array
 * @buffer_ind: char sequence length
 */
void print_buffer(char buffer[], int *buffer_ind)
{
	if (buffer_ind > 0)
	{
		write(1, &buffer[0], *buffer_ind);
	}

	*buffer_ind = 0;
}
