#include "main.h"

/**
 * _strlen - length of string
 * @s: variable input string
 * Return: integer
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
