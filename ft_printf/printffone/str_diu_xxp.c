/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_diu_xxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:51 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/25 14:15:37 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *mal_diux(t_format fmt, int str, int base);

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


    count = countd(str, base) + need_space(str, fmt);
    if (fmt.precision >= fmt.width && fmt.precision >= count)
        ret = malloc(sizeof(char) * (fmt.precision + 1 + need_space(str, fmt)));
    else if (fmt.width > count && fmt.width > fmt.precision)
        ret = malloc(sizeof(char) * (fmt.width + 1));
    else
        ret = malloc(sizeof(char) * (count + 1));
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

void    init_diux(t_format fmt, char **str)
{
    //put spaces for the lenght
    //put 0 when it needs
    //put sign/0x
}
