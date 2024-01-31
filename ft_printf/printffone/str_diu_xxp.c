/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_diu_xxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:51 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/30 16:42:37 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *mal_diux(t_format fmt, int str, int base);

char *str_num(t_format fmt, int str)
{
	char	*ret;
	char conv;

	conv = fmt.conversion;
	if (conv == 'd' || conv == 'i' || conv == 'u')
		ret = mal_diux(fmt, str, 10);
	if (conv == 'x' || conv == 'X')
		ret = mal_diux(fmt, str, 16);
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
    startind = init_diux(fmt, ret, len, base);
    ft_memset(ret + startind, need_sign(fmt, str), need_space(str, fmt));
    write_num(fmt, startind + need_space(str, fmt), str, base);
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

int    init_diux(t_format fmt, char *str, int len, int base)
{
	int i;
	char pad;
	int	startindex;
	char	*strnum;
	i = need_space(*str, fmt);
	pad = needed_pad(fmt);
	ft_memset(*str, pad, len);
	if (ft_strchar(fmt, '-'))
		startindex = need_space(str, fmt);
	else 
		if (fmt.precision >= countd(str, base) + need_space(str, fmt);
			startindex = fmt.width - (fmt.precision + i);
		else
			startindex = fmt.width - countd(str, base) + i;
	ft_memset(*(str + startindex), '0', fmt.precision);
	return (startindex);
}
