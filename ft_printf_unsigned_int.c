/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:11:50 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/21 15:10:10 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_printf_uint(t_conversion *c)
{
	unsigned int	n;
	char			*s;
	int				count;

	n = va_arg(c->args, unsigned int);
	s = ft_itoa_unsigned(n);
	count = write(1, s, ft_strlen(s));
	free(s);
	return (count);
}
