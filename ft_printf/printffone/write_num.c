/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:44:51 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/31 16:45:13 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_num(t_format fmt, int index, long int number, char *dest)
{
	char	*ito;
	char	*base;
	char	c;
	long unsigned int num;

	c = fmt.conversion;
	num = number;
	base = "0123456789";
	if (number < 0)
		num = -num;
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	ito = ft_itoa_base(num, base);
	ft_memcpy(dest + index, ito, ft_strlen(ito));
	free(ito);
}
