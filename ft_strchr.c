/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:53:40 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/06 17:05:16 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// PS: c % 256 because we compare an int to a char (biggest char=256)
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c % 256)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c % 256)
		return ((char *)(s + i));
	return (NULL);
}
