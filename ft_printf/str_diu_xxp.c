#include "ft_printf.h"

char *str_num(t_format format, int str)
{

    return (ret);
}

char    *init_num_format(t_format format, int str)
{
    char    *ret;
    int     count;

    count = countd(str) + need_space(str, format);
    if (format.pflag)
    {
        if (format.precision > format.width)

    }
    else if (format.width > count)
        ret = malloc(sizeof(char) * (format.width + 1));
    else
        ret = malloc(sizeof(char) * (count + 1));
}