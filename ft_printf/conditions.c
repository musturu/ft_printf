#include "ft_printf.h"

int	is_accepted_conv(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' 
	|| c == 'i' || c == 'u'|| c == 'x' 
	|| c == 'X' || c == '%') 
		return (1);
	else
		return 0;
}

int	is_accepted_flag(int c)
{
	if (c == '-' || c == ' ' || c == '0' || c == '#' 
	|| c == '+')
		return (1);
	else
		return 0;
}

int is_signed(int c, t_format format)
{
    if (c < 0 || ft_strchr(format.flags, '+'))
        return (1);
    else
        return (0);
}

int need_space(int c, t_format format)
{
    if (is_signed(c, format))
        return (1);
    else if (ft_strchr(format.flags, ' '))
        return (1);
    else
        return (0);

}