/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:04:03 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/31 13:49:01 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	getpower(unsigned int count, int basenum)
{
	unsigned int	i;

	i = 1;
	while (count > 1)
	{
		i *= basenum;
		count--;
	}
	return (i);
}


char	*ft_itoa_base(unsigned int number, char *base)
{
	int basen;
	int ipwr;
	char *ret;
	char i;

	basen = ft_strlen(base);
	i = 0;
	ipwr = getpower(countd(number, basen), basen);
	ret = ft_calloc(sizeof(char), countd(number, basen));
	while (ipwr != 0)
	{
		ret[i++] = base[(number / ipwr)];
		number %= ipwr;
		ipwr /= basen;
	}
	return (ret);
}