#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_format
{
	char	*flags;
	int		width;
	int		precision;
	int		pflag;
	char	conversion;
	
	pflag = 0;
} t_format;

int	ft_printf(const char *str, ...);
void	pipeline(const char *str, va_list ap, int count);
char *get_format(const char* str);
void	format_read(const char *format);
int	is_accepted_flag(int c);
int	is_accepted_conv(int c);