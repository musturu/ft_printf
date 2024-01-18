#include "ft_printf.h"


/*
-	Left-justify within the given field width;

+	Forces to preceed the result with a plus or minus sign (+ or -);

(space)	If no sign is going to be written, a blank space 
	is inserted before the value. 

#	Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X 
	respectively for values different than zero.

0	Left-pads the number with zeroes (0) instead of spaces
	when padding is specified

[width] 	Minimum number of characters to be printed.

[.precision] For integer specifiers (d, i, o, u, x, X): precision specifies
	the minimum number of digits to be written
	For s: this is the maximum number of characters to be printed.

*/
typedef struct s_format
{
	char	*flags;
	int		width;
	int		precision;
	int		pflag;
	char	conversion;
	
	pflag = 0;
} t_format;

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	*ap;
	int i;

	ap = va_start(ap, str);
	count = 0;
	while (1)
	{
		/* code */
	}
	return (count);
}

void	pipeline(const char *str, va_list ap, int *count)
{
	/*
	get format
	read format creates a t_format variable
	stringify with resolved flags
	write
	clean free
	*/
}

char *get_format(const char *str)
{
	int	i;

	i = 0;
	while (is_accepted_flag(*str[i]))
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

t_format	format_read(const char *format)
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
	f.precision = ft_atoi(format + i + 1);
	while (ft_isdigit(format[i]))
		i++;
	f.conversion = format[i];
	f.flags = flags;
	return (f);
	free(format);
}

char	*stringify(t_format format, va_list ap)
{
	if (format.conversion == '%')
		return	str_perc(format);
	if (format.conversion == 'c')
		return	str_c(format, va_arg(args, int));
	if (format.conversion == 's')
		return	str_s(format, va_arg(args, char *));
	if (format.conversion == 'p')
		return	str_ptrnum(format, va_arg(args, void*));
	if (format.conversion == 'd')
		return	str_num(format, va_arg(args, int));
	if (format.conversion == 'i')
		return	str_num(format, va_arg(args, int));
	if (format.conversion == 'u')
		return	str_num(format, va_arg(args, int));
	if (format.conversion == 'x')
		return	str_hexnum(format, va_arg(args, unsigned int));
	if (format.conversion == 'X')
		return	str_hexnum(format, va_arg(args, unsigned int));
}

