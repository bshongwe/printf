#include "main.h"

/** Print char **/
/**
 * print_char -  char print function
 * @types: var args list
 * @buffer: print handling buffer temp pointer
 * @flags: flags handler for macros or enum values
 * @width: width print handler
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/** Print string **/
/**
 * print_string - string func
 * @types: args list
 * @buffer: An array that acts as a temporary storage location
 * @flags: Macros or enum values
 * @width: Specifies the minimum width of the printed output
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/** Print percent sign **/
/**
 * print_percent - functions that prints a percent sign
 * @types: List of variable arguments passed to the function
 * @buffer: An array that acts as a temporary storage location
 * @flags: Macros or enum values
 * @width: Specifies the minimum width of the printed output
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/** Print Int **/
/**
 * print_int - function that print int
 * @types: List of variable arguments passed to the function
 * @buffer: An array that acts as a temporary storage location
 * @flags: Macros or enum values
 * @width: Specifies the minimum width of the printed output
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(is_negative, a, buffer, flags, width, precision, size));
}

/** Print binary **/
/**
 * print_binary - function that prints an unsigned number
 * @types: List of variable arguments passed to the function
 * @buffer: An array that acts as a temporary storage location
 * @flags: Macros or enum values
 * @width: Specifies the minimum width of the printed output
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, a, sum, a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (a = 1; a < 32; a++)
	{
		m /= 2;
		a[a] = (n / m) % 2;
	}
	for (a = 0, sum = 0, count = 0; a < 32; a++)
	{
		sum += a[a];
		if (sum || a == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}