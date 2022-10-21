/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:11:50 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/21 15:20:05 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf_ptr(t_conversion *c)
{
	unsigned long int	ptr;
	char				*s;

	ptr = va_arg(c->args, unsigned long int);
	write(1, "0x", 2);
	s = ft_itoa_hex_long(ptr, 0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s) + 2);
}
