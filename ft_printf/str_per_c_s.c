#include "ft_printf.h"

char *str_c(t_format format, int c)
{
    char    *ret;
    int     len;

    if (format.width == 0)
        ret = malloc(sizeof(char) * 2);
    else
        ret = malloc(sizeof(char * (format.width + 1)));
    if (ret == NULL)
        return (NULL);
    ft_memset(ret, ' ', ft_strlen(ret) - 1);
    if (ft_strchr(format.flags, '-'))
        ret[0] = c;
    else
        ret[ft_strlen(ret) - 1] = c;
    return (ret);
}

char *str_perc(t_format format)
{
    char    *ret;

    if (format.width == 0 && format.flags = NULL && format.pflag == 0)
        ret = malloc(sizeof(char) * 2);
    if (ret == NULL)
        return (NULL);
        ret[0] = '%';
    return (ret);
}


char *str_s(t_format format, char *str)
{
    char    *ret;
    int     len;

    len = ft_strlen(str);
    if (len > format.width)
    {
        if (pflag)
        {
            if (format.precision < len)
                ret = malloc(sizeof(char) * (precision + 1));
        }
        else
            ret = malloc(sizeof(char) * (len + 1));
    }
    else
        ret = malloc(sizeof(char * (format.width + 1)));
    if (ret == NULL)
        return (NULL);
    ft_memset(ret, ' ', ft_strlen(ret) - 1);
    if (ft_strchr(format.flags, '-'))
        ft_strlcpy(ret, str, len)
    else
        ft_strlcpy(ret + (ft_strlen(ret) - len), str, len);
    return (ret);
}