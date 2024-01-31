/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_diu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:51 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/31 18:38:47 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *mal_diux(t_format fmt, int str, int base);
int    init_diux(t_format fmt, char *str, int len, int base);

char *str_num(t_format fmt, int str)
{
	char	*ret;

	ret = mal_diux(fmt, str, 10);
	return (ret);
}

static char    *mal_diux(t_format fmt, int str, int base)
{
    char    *ret;
    int     count;
    int		len;
    int	startind;

    count = countd(str, base) + need_space(str, fmt);
    if (fmt.precision >= fmt.width && fmt.precision >= count)
	    len = fmt.precision + need_space(str, fmt);
    else if (fmt.width > count && fmt.width > fmt.precision)
	    len = fmt.width;
    else
	    len = count;
    ret = malloc(sizeof(char) * (len + 1));
    if (ret == NULL)
	    return (NULL);
    startind = init_diux(fmt, ret, len, str);
    write_num(fmt, startind + need_space(str, fmt), str, ret);
    put_sign(fmt, str, ret);
    return (ret);
}

static char    *mal_p(t_format fmt, int str)
{
    char    *ret;
    int     count;
    count = countd(str, 16) + 2;
    if (fmt.width > count + fmt.precision)
        ret = malloc(sizeof(char) * (fmt.width + 1));
    else
        ret = malloc(sizeof(char) * (count + 1 + fmt.precision));
    return (ret);
}

int    init_diux(t_format fmt, char *str, int len, int num)
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
	return (startindex);
	/*
	int i;
	char pad;
	int	startindex;
	int base;
	base = get_base(fmt);
	i = need_space(num, fmt);
	pad = needed_pad(fmt);
	ft_memset(str, pad, len);
	if (ft_strchr(fmt.flags, '-'))
		startindex = need_space(num, fmt);
	else 
		if (fmt.precision > countd(num, base) + i)
			startindex = len - (countd(num, base) + i);
		else
			startindex = len - (countd(num, base) + i);
	ft_memset((str + i), '0', fmt.precision);
	return (startindex);*/
}

