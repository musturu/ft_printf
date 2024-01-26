#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
/*	char *asd = get_format(argv[1]);
	printf("format: %s\n", asd);

	t_format format = read_format(asd);
	printf("flags: %s\n", format.flags);
	printf("width: %i\n", format.width);
	printf("precision: %i\n", format.precision);
	printf("conversion: %c\n", format.conversion);
*/
	int i =	printf("prova 1: questo %050.20%\n");
	int j = ft_printf("prova 1: questo %050.20%\n");

	printf("originale: %d\n mio: %d\n", i, j);
}
