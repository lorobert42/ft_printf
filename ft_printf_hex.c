/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:11:50 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/21 22:52:22 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_printf_hex(t_conversion *c, int is_upp)
{
	unsigned int	n;
	char			*s;
	int				count;

	n = va_arg(c->args, unsigned int);
	s = ft_itoa_hex(n, is_upp);
	count = write(1, s, ft_strlen(s));
	free(s);
	return (count);
}
