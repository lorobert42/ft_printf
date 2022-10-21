/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:11:50 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/21 15:24:44 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf_hex(t_conversion *c, int is_upp)
{
	unsigned int	n;
	char			*s;

	n = va_arg(c->args, unsigned int);
	write(1, "0x", 2);
	s = ft_itoa_hex(ptr, is_upp);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s) + 2);
}
