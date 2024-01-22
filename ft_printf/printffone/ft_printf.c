/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:15 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/22 17:50:24 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



/*
-	Left-justify within the given field width;

+	Forces to preceed the result with a plus or minus sign (+ or -);

(space)	If no sign is going to be written, a blank space 
	is inserted before the value. 

#	Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X 
	respectively for values different than zero.

0	Left-pads the number with zeroes (0) instead of spaces
	when padding is specified

[width] 	Minimum number of characters to be printed.

[.precision] For integer specifiers (d, i, o, u, x, X): precision specifies
	the minimum number of digits to be written
	For s: this is the maximum number of characters to be printed.

*/

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	*ap;
	int i;

	ap = va_start(ap, str);
	count = 0;
	while (1)
	{
		/* code */
	}
	return (count);
}

char	*stringify(t_format format, va_list ap)
{
	if (format.conversion == '%')
		return	str_perc(format);
	if (format.conversion == 'c')
		return	str_c(format, va_arg(args, int));
	if (format.conversion == 's')
		return	str_s(format, va_arg(args, char *));
	if (format.conversion == 'p')
		return	str_ptrnum(format, va_arg(args, void*));
	if (format.conversion == 'd')
		return	str_num(format, va_arg(args, int));
	if (format.conversion == 'i')
		return	str_num(format, va_arg(args, int));
	if (format.conversion == 'u')
		return	str_num(format, va_arg(args, int));
	if (format.conversion == 'x')
		return	str_hexnum(format, va_arg(args, unsigned int));
	if (format.conversion == 'X')
		return	str_hexnum(format, va_arg(args, unsigned int));
}

void	pipeline(const char *str, va_list ap, int *count)
{
	/*
	get format
	read format creates a t_format variable
	stringify with resolved flags
	write
	clean free
	*/
}
