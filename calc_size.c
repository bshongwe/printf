#include "main.h"

/**
 * calc_size - handle cast args size
 * @fmt: string arg format
 * @a: all args list
 * Return: size (Success)
 */
int calc_size(const char *fmt, int *a)
{
	int curr_a = *a + 1;
	int size = 0;

	if (fmt[curr_a] == 'l')
	{
		size = S_LONG;
	}
	else if (fmt[curr_a] == 'h')
	{
		size = S_SHORT;
	}

	if (size == 0)
	{
		*a = curr_a - 1;
	}
	else
	{
		*a = curr_a;
	}

	return (size);
}
