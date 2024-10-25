/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:33 by mjuncker          #+#    #+#             */
/*   Updated: 2024/10/24 17:57:46 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// \0 included in dsize, (Hello world > 11 char but dsize = 12)
size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	y;
	size_t	i;

	if (dsize == 0)
		return (0);
	if (ft_strlen(dst) > dsize)
		return (dsize + ft_strlen(src));
	i = 0;
	y = 0;
	while (dst[y] && y < dsize)
		y++;
	while (src[i] && y < dsize - 1)
	{
		dst[y] = src[i];
		y++;
		i++;
	}
	dst[y] = '\0';
	return (ft_strlen(src) + (y - i));
}
