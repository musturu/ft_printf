/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:53:46 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/31 16:34:13 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	needed_pad(t_format fmt)
{
	if (!ft_strchr(fmt.flags, '-') && ft_strchr(fmt.flags, '0') && !fmt.pflag) 
			return ('0');
	else
		return (' ');
	
}

char *need_sign(t_format fmt, int c)
{
	char conv;

	conv = fmt.conversion;
          if ((conv == 'x' || conv == 'X') && ft_strchr(fmt.flags, '#'))
		  if (conv == 'x')
			  return ("0x");
		  else 
			  return ("0X");
      if (is_signed(c, fmt))
	      if (c < 0)
		      return ("-");
	      else
		      return ("+");
      else if (ft_strchr(fmt.flags, ' ')
          && (conv == 'd' || conv == 'i') && fmt.width == 0 && !fmt.pflag)
          return (" ");
      else
         return (0);
}

void	put_sign(t_format fmt, int num, char *dest)
{
	int i;

	i = need_space(num, fmt);
	while(*dest)
	{
		if (ft_isalnum(*dest))
		{
			ft_memcpy(dest - i, need_sign(fmt, num), i);
			return ;
		}
		dest++;
	}
}
