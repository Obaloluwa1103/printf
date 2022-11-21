#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - prints a string
 * @format: string to print (char *)
 * @...: unknown variadic parameters
 *
 * Return: numbers of printed characters
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int value = 0;

	va_list args;

	va_start(args, format);

	int (*f)(va_list);

	/*excludes null pointer from getting passed*/
	if (format == NULL)
	{
		return (-1);
	}
	/*prints string characters*/
	while (format[i])
	{
	if (format[i] != '%')
	{
	value = write(1, &format[i], 1);
	count = count + value;
	i++;
	continue;
	}
	if (format[i] == '%')
	{
	f = check_specifier(&format[i + 1]);
	if (f != NULL)
	{
	value = f(args);
	count = count + value;
	i = i + 2;
	continue;
	}
	if (format[i + 1] == '\0')
	{
	break;
	}
	if (format[i + 1] != '\0')
	{
	value = write(1, &format[i + 1], 1);
	count = count + value;
	i = i + 2;
	continue;
	}
	}
	}
	return (count);
}
