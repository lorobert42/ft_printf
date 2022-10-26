/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:11:50 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/26 09:36:52 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_printf_ptr(t_conversion *c)
{
	unsigned long int	ptr;
	char				*s;
	int					count;

	ptr = va_arg(c->args, unsigned long int);
	if (!ptr)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	s = ft_itoa_hex_long(ptr, 0);
	count = write(1, s, ft_strlen(s));
	free(s);
	return (count + 2);
}
