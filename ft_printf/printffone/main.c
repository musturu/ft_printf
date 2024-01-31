#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	printf("%s\n" , ft_itoa_base(12345, "0123456789"));
	char	*prova = "%#10.15d\n";
	int i = printf(prova, 392);
	int j = ft_printf(prova, 392);
	printf("mio %d, originale %d \n", j, i);
}
