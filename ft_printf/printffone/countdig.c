#include "ft_printf.h"

int	countdig(long int num, int base)
{
	int	count;

	count = 1;
	while(num / base != 0)
	{
		count++;
		num = num / base;
	}
	return (count);
}
