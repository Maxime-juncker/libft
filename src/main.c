#include "libft/io.h"
#include "libft/string.h"

#include <stdio.h>

int main(void)
{
	char buffer[1024] = {0};
	// int	a = 2;
	// ft_sprintf( buffer, sizeof(buffer), "hello world %s %d %x %X %i %u %c\n ptr:%p", "test", 
	// 		-128, 42, 42, 42, -1, 'a', &a);
	//
	// printf("hello world %s %d %x %X %i %u %c\n ptr:%p", "test", 
	// 		-128, 42, 42, 42, -1, 'a', &a);
	// // ft_sprintf( buffer, sizeof(buffer), "hello world %s %d %x %X %i %u %c\n ptr:%p", "test", 
	// ft_sprintf(buffer, sizeof(buffer), "%p %x %u\n", &a, &a, &a);
	// printf("%p %x %u\n", &a, &a, &a);
	// ft_putaddr((unsigned long)&a, "0123456789abcdef", 1);
	//
	ft_sprintf(buffer, sizeof(buffer), 
			"hello |%-10f|\n", 1.5);
	printf( "hello |%-10f|\n", 1.5);

	return 0;
}
