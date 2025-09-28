#include "libft/io.h"
#include "libft/string.h"

#include <stdio.h>

int main(void)
{
	char buffer[1024] = {0};
	ft_sprintf( buffer, sizeof(buffer), "hello world %s test", "test");
	return 0;
}
