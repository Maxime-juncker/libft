#include "libft/io.h"
#include "libft/string.h"

#include <stdio.h>

int main(void)
{
	char buffer[1024] = {0};
	ft_sprintf( buffer, sizeof(buffer), "hello world %s %d %x %X %i %u test", "test", -128, 42, 42, 42, -1);
	return 0;
}
