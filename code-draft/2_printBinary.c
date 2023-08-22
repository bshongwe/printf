/* Task 2 */
#include "main.h"

void printBinary(unsigned int num)
{
	if (num > 1)
	{
	printBinary(num / 2);
	}
	printf("%d", num % 2);
}

int customPrintf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int printedCount = 0;

	while (*format)
	{
	if (*format == '%' && *(format + 1) == 'b')
	{
	format += 2;
	unsigned int num = va_arg(args, unsigned int);

	printBinary(num);
	printedCount += sizeof(unsigned int) * 8;
	}
	else
	{
	putchar(*format);
	format++;
	printedCount++;
	}
	}

	va_end(args);
	return (printedCount);
}

int main(void)
{
	unsigned int value = 42;

	customPrintf("Binary representation of %u is %b.\n", value, value);
	return (0);
}
