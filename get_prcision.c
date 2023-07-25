#include "main.h"
/**
 * get_precision - calculate printing precision
 * @format: formatted string
 * @i: list of arguments which are to be printed
 * @list: list of arguments
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
        int c = *i + 1;
        int p = -1;

        if (format[c] != '.')
                return (p);
        p = 0;
        for (c += 1; format[c] != '\0'; c++)
        {
                if (is_digit(format[c]))
                {
                        p *= 10;
                        p += format[c] - '0';
                }
                else if (format[c] == '*')
                {
                        c++;
                        p = va_arg(list, int);
                        break;
                }
                else
                        break;
	}
	*i = c - 1;
	return (p);
}
