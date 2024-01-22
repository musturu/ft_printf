/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_diu_xxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:51 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/22 14:50:37 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *str_num(t_format fmt, int str)
{

    return (ret);
}

static char    *mal_diux(t_format fmt, int str)
{
    char    *ret;
    int     count;
    count = countd(str) + need_space(str, fmt);
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
    count = countd(str) + 2;
    if (fmt.width > count + fmt.precision)
        ret = malloc(sizeof(char) * (fmt.width + 1));
    else
        ret = malloc(sizeof(char) * (count + 1 + fmt.precision));
    return (ret);
}

void    init_diux(t_format, fmt, char **str)
{
    //put spaces for the lenght
    //put 0 when it needs
    //put sign/0x
}
