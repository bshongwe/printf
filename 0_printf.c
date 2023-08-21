#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0')
    {
    	if (*format == '%')
    	{
    		format++;

    		if (*format == '\0')
    			break;

            	if (*format == 'c')
            	{            		
                	char c = (char) va_arg(args, int);
                	putchar(c);
                	count++;
            	}
            	else if (*format == 's')
            	{               	
                	char *str = va_arg(args, char *);
                	while (*str != '\0')
                	{
                    		putchar(*str);
                    		str++;
                    		count++;
                	}
            	}
            	else if (*format == '%')
            	{                	
                	putchar('%');
                	count++;
            	}
            	else
            	{                	
                	putchar('%');
                	putchar(*format);
                	count += 2;
            	}
        }
        else
        {        	
            	putchar(*format);
            	count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
