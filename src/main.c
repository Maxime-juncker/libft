#include "libft/io.h"
#include <stdio.h>

int main(void)
{
	int		size = 0;
	int		size2 = 0;

	size = ft_printf("hello %s", "world\n");
	size2 = printf("hello %s", "world\n");

	printf("size: %d\nsize2: %d\n", size, size2);
	return 0;
}
