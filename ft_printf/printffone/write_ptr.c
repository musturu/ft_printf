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

void	write_ptr(t_format fmt, int index, uintptr_t number, char *dest)
{
	char	*ito;
	char	*base;
	char	c;
	uintptr_t num;

	c = fmt.conversion;
	num = number;
	if (number < 0)
		num = -num;
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'i' || c == 'u' || c == 'd')
		base = "0123456789";
	ito = ft_itoa_base_ptr(num, base);
	ft_memcpy(dest + index, ito, ft_strlen(ito));
	free(ito);
}
