/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:42:36 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/31 18:22:28 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    init_x(t_format fmt, char *str,int len,unsigned int num)
{
	int i;
	char pad;
	int	startindex;
	int base;

	base = get_base(fmt);
	i = need_space(num, fmt);
	pad = needed_pad(fmt);
	ft_memset(str, pad, len);
	if (ft_strchr(fmt.flags, '-') && fmt.precision <= countd(num, base))
		startindex = need_space(num, fmt);
	if (ft_strchr(fmt.flags, '-') && fmt.precision > countd(num, base))
		startindex = i + fmt.precision - countd(num, base);
	else if (!ft_strchr(fmt.flags, '-')) 
		if (fmt.precision > countd(num, base) + i)
			startindex = len - (countd(num, base));
		else
			startindex = len - (countd(num, base) + i);
	ft_memset((str + i), '0', fmt.precision);
	printf("%d" , startindex);
	return (startindex);
}

static char    *mal_x(t_format fmt, unsigned int str)
{
    char    *ret;
    int     count;
    int		len;
    int	startind;

    count = countd(str, 16) + need_space(str, fmt);
    if (fmt.precision >= fmt.width && fmt.precision >= count)
	    len = fmt.precision + need_space(str, fmt);
    else if (fmt.width > count && fmt.width > fmt.precision)
	    len = fmt.width;
    else
	    len = count;
    ret = malloc(sizeof(char) * (len + 1));
    if (ret == NULL)
	    return (NULL);
    startind = init_x(fmt, ret, len, str);
    write_num(fmt, startind, str, ret);
    put_sign(fmt, str, ret);
    return (ret);
}

char	*str_hexnum(t_format fmt, unsigned int str)
{
	char	*ret;
	ret = mal_x(fmt, str);
	return (ret);
}

