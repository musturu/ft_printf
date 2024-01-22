/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:13:13 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/22 16:14:21 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *get_format(const char *str)
{
	int	i;

	i = 0;
	while (is_accepted_flag(str[i]))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		i++;
	}
	if (is_accepted_conv(str[++i]))
		return (ft_substr(str, 0, i));
	else
		return (NULL);
}

t_format	format_read(char *format)
{
	char		*flags;
	int			i;
	t_format	f;

	i = 0;
	flags = ft_calloc(ft_strlen(format), sizeof(char));
	while (is_accepted_flag(format[i]))
		flags[i++] = format[i++];
	f.width = ft_atoi(format + i);
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
		f.pflag = 1;
	else
		f.pflag = 0;
	f.precision = ft_atoi(format + i + 1);
	while (ft_isdigit(format[i]))
		i++;
	f.conversion = format[i];
	f.flags = flags;
	return (f);
	free(format);
}
