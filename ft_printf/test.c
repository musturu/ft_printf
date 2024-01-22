/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:04 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/22 15:27:51 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/ft_printf.h"

char	*get_format(const char *str);

int	main()
{
	char	*str = "asd%- 50.5d";
	printf("%s\n", get_format(str));
}

