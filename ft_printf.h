#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdbool.h>

int	ft_printf(const char *format, ...);

typedef struct s_conversion {
	va_list	args;
	bool	minus;
	bool	zero;
	bool	point;
	bool	hash;
	bool	space;
	bool	plus;
	int		width;
	int		precision;
	char	specifier;
}	t_conversion;

#endif
