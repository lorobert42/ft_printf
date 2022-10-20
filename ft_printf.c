#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

#include <stdio.h>

int	parse_conversion(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		printf("char");
	else if (*format == 's')
		printf("string");
	else if (*format == 'p')
		printf("ptr");
	else if (*format == 'd' || *format == 'i')
		printf("int");
	else if (*format == 'u')
		printf("uint");
	else if (*format == 'x')
		printf("HEX");
	else if (*format == 'X')
		printf("hex");
	else
		return (count);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	int		tmp;
	va_list	args;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			res++;
			printf("%c", *format);
			format++;
			continue ;
		}
		tmp = parse_conversion(++format, args);
		format++;
		res += tmp + 1;
	}
	va_end(args);
}
