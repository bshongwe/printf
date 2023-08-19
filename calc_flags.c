#include "main.h"

/**
 * calc_flags - func handles flags
 * @format: arg string format
 * @a: input param
 * Return: flags (Success)
 */
int calc_flags(const char *format, int *a)
{
	int j, curr_a;
	int flags = 0;
	const char FL_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FL_ARR[] = {FN_MINUS, FN_PLUS, FN_ZERO, FN_HASH, FN_SPACE, 0};

	for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
	{
		for (j = 0; FL_CH[j] != '\0'; j++)
			if (format[curr_a] == FL_CH[j])
			{
				flags |= FL_ARR[j];
				break;
			}

		if (FL_CH[j] == 0)
		{
			break;
		}
	}

	*a = curr_a - 1;

	return (flags);
}
