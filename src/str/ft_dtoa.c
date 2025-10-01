/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:17:16 by mjuncker          #+#    #+#             */
/*   Updated: 2025/10/01 14:19:02 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

char	*ft_dtoa(char *buffer, size_t size, double d, int precision)
{
	long	dec;
	double	fract;
	char	buff[1024];
	int		i;

	dec = (long)d;
	fract = d - dec;
	i = 1;
	while (fract != (long)fract)
	{
		if (i > precision)
			break ;
		fract *= 10;
		i++;
	}
	ft_itoa(buff, sizeof(buff), dec);
	ft_strlcat(buffer, buff, size);
	ft_strlcat(buffer, ".", size);
	ft_itoa(buff, sizeof(buff), fract);
	ft_strlcat(buffer, buff, size);
	return (buffer);
}
