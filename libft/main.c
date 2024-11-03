/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:45:34 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/03 16:53:38 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>

void	basic_tests();
void	print_arr(char *msg, int *arr, size_t size);


int main(int argc, const char *argv[])
{
	// is____ tests
	basic_tests("ft_isalpha", &ft_isalpha, &isalpha);
	basic_tests("ft_isdigit", &ft_isdigit, &isdigit);
	basic_tests("ft_isalnum", &ft_isalnum, &isalnum);
	basic_tests("ft_isascii", &ft_isascii, &isascii);
	basic_tests("ft_isprint", &ft_isprint, &isprint);

	// strlen
	printf("ft_strlen(bonjour): %d (%d)\n", ft_strlen("bonjour"), strlen("bonjour"));
	printf("ft_strlen(): %d (%d)\n\n", ft_strlen(""), strlen(""));

	// memset
	char *str;
	str = malloc(30 * sizeof(char));
	bzero(str, 30);
	str = (char *)ft_memset(str, 'c', 4);
	printf("ft_memset(str, c, 4): %s\n\n", str);

	// bzero
	ft_bzero(str, 5);
	printf("ft_bzero(str, 5): %s\n\n", str);

	// memcpy
	bzero(str, 30);
	ft_memcpy(str, "bonjour", 30);
	printf("ft_memcpy(str, bonjour 30): %s\n", str);
	bzero(str, 30);
	ft_memcpy(str, "", 30);
	if (str == NULL)
		printf("ft_memcpy(str, , 30)\n: (null)");
	else
		printf("ft_memcpy(str, , 30): %s\n", str);
	bzero(str, 30);
	ft_memcpy(str, "bonjour", 2);
	printf("ft_memcpy(str, bonjour 2): %s\n\n", str);
	bzero(str, 30);

	// memmove
	int	backup[] = {0, 1, 2, 3, 4};
	int	arr[] = {0, 1, 2, 3, 4};
	int	test[] = {6, 7, 8, 9, 10};
	print_arr("arr: ", arr, 5);
	print_arr("test: ", test, 5);
	ft_memmove(arr, test, 5 * sizeof(int));
	print_arr("ft_memmove(arr, test, 5 * sizeof(int)): ", arr, 5);
	memcpy(arr, backup, 5 * sizeof(int));
	ft_memmove(arr, test, 2 * sizeof(int));
	print_arr("ft_memmove(arr, test, 2 * sizeof(int)): ", arr, 5);
	memcpy(arr, backup, 5);
	ft_memmove(arr, arr + 2, 3 * sizeof(int));
	print_arr("ft_memmove(arr, arr + 2, 3 * sizeof(int)): ", arr, 5);
	memcpy(arr, backup, 5);
	printf("\n");

	// strlcpy
	printf("ft_strlcpy(str, bonjour, 10): %d (%s)\n", ft_strlcpy(str, "bonjour", 10), str);
	printf("ft_strlcpy(str, bonjour, 5): %d (%s)\n", ft_strlcpy(str, "bonjour", 5), str);
	printf("ft_strlcpy(str, , 10): %d (%s)\n", ft_strlcpy(str, "", 10), str);

	// strclat
	
	return (0);
}

void	print_arr(char *msg, int *arr, size_t size)
{
	int	i;

	printf("%s", msg);
	i = 0;
	while (i < size)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("\n");
}

void	basic_tests(char *name, int (*ft_f)(int c), int (*f)(int c))
{
	// is alpha
	printf("%s(a): %d (%d)\n", name, 	ft_f('a'), 	f('a'));
	printf("%s(z): %d (%d)\n", name, 	ft_f('z'), 	f('z'));
	printf("%s(0): %d (%d)\n", name, 	ft_f('0'), 	f('0'));
	printf("%s(\\n): %d (%d)\n", name, 	ft_f('\n'),	f('\n'));
	printf("%s(-1): %d (%d)\n", name,	ft_f(-1), 	f(-1));
	printf("%s(104): %d (%d)\n", name, 	ft_f(104), 	f(104));
	printf("\n");
}
