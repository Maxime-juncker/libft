/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:58:59 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 11:24:17 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == c % 256)
			j = i;
		i++;
	}
	if (s[i] == c % 256)
		return ((char *)(s + i));
	if (j > -1)
		return ((char *)(s + j));
	return (NULL);
}
