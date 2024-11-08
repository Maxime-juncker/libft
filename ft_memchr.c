/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:28:38 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/07 08:14:54 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// PS: c % 256 because we compare an int to a char (biggest char=256)
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_memcmp(s, (void *)(&c), 1) == 0)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
