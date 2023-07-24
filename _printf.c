#include "main.h"

/**
 * print_output - Prints the contents of the buffer if it exists
 * @buff: Array of chars representing the buffer
 * @index: Pointer to the current index in the buffer
 */
void print_output(char buff[], int *index);

/**
 * printf_custom - Custom printf function
 * @format: The format string
 * Return: Number of printed characters
 */
int printf_custom(const char *format, ...)
{
	int j, total_printed = 0, printed_chars = 0;
	int flags, width, precision, size, index = 0;
	va_list args;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buff[index++] = format[j];
			if (index == BUFF_SIZE)
				print_output(buff, &index);
			printed_chars++;
		}
		else
		{
			print_output(buff, &index);
			flags = get_flags(format, &j);
			width = get_width(format, &j, args);
			precision = get_precision(format, &j, args);
			size = get_size(format, &j);
			++j;
			total_printed = handle_print(format, &j, args, buff,
				flags, width, precision, size);
			if (total_printed == -1)
				return (-1);
			printed_chars += total_printed;
		}
	}

	print_output(buff, &index);

	va_end(args);

	return (printed_chars);
}

/**
 * print_output - Prints the contents of the buffer if it exists
 * @buff: Array of chars representing the buffer
 * @index: Pointer to the current index in the buffer
 */
void print_output(char buff[], int *index)
{
	if (*index > 0)
		write(1, &buff[0], *index);

	*index = 0;
}
