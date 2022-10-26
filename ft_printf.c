/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:54:02 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/26 10:04:23 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	parse_conversion(const char **format, t_conversion *c)
{
	int	count;

	count = 0;
	if (**format == 'c')
		count += ft_printf_char(c);
	else if (**format == 's')
		count += ft_printf_string(c);
	else if (**format == 'p')
		count += ft_printf_ptr(c);
	else if (**format == 'd' || **format == 'i')
		count += ft_printf_int(c);
	else if (**format == 'u')
		count += ft_printf_uint(c);
	else if (**format == 'x')
		count += ft_printf_hex(c, 0);
	else if (**format == 'X')
		count += ft_printf_hex(c, 1);
	else if (**format == '%')
		count += write(1, "%", 1);
	else
		count = -1;
	return (count);
}

int	parse_format(const char **format, t_conversion *c)
{
	int	count;

	count = 0;
	if (**format != '%')
		count = write(1, *format, 1);
	else
	{
		(*format)++;
		count = parse_conversion(format, c);
	}
	(*format)++;
	return (count);
}

void	init_conversion(t_conversion **c)
{
	(*c)->minus = 0;
	(*c)->zero = 0;
	(*c)->point = 0;
	(*c)->hash = 0;
	(*c)->space = 0;
	(*c)->plus = 0;
	(*c)->width = 0;
	(*c)->precision = 0;
	(*c)->specifier = 0;
}

int	ft_printf(const char *format, ...)
{
	int				count;
	int				value;
	t_conversion	*conversion;

	count = 0;
	conversion = malloc(sizeof(t_conversion));
	if (!conversion)
		return (-1);
	init_conversion(&conversion);
	va_start(conversion->args, format);
	while (*format)
	{
		value = parse_format(&format, conversion);
		if (value < 0)
			return (-1);
		count += value;
	}
	va_end(conversion->args);
	free(conversion);
	return (count);
}
