/* Task 3 */
#include "main.h"

void printInteger(unsigned int num, char specifier)
{
	switch (specifier)
	}
	case 'u':
	printf("%u", num);
	break;
	case 'o':
	printf("%o", num);
	break;
	case 'x':
	printf("%x", num);
	break;
	case 'X':
	printf("%X", num);
	break;
	default:
	printf("Invalid specifier: %c", specifier);
	break;
	}
}

int main(void)
{
	unsigned int number = 255;

	printf("Decimal: ");
	printInteger(number, 'u');
	printf("\n");

	printf("Octal: ");
	printInteger(number, 'o');
	printf("\n");

	printf("Lowercase Hexadecimal: ");
	printInteger(number, 'x');
	printf("\n");

	printf("Uppercase Hexadecimal: ");
	printInteger(number, 'X');
	printf("\n");

	return (0);
}

