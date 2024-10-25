/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:45:34 by mjuncker          #+#    #+#             */
/*   Updated: 2024/10/24 21:55:34 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>
#include <stdio.h>

int		main(void)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	memset(dest, 'r', 15);
	printf("%ld %s\n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 5), dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 15);
	printf("%ld %s\n",strlcat(dest, "lorem ipsum dolor sit amet", 5), dest);
}