/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:04:13 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 11:24:17 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/memory.h"

char	*ft_itoa(char *buffer, size_t size, int n)
{
	return (ft_itoa_base(buffer, size, n, "0123456789"));
}

char	*ft_itoa_base(char *buffer, size_t size, int n, const char *base)
{
	int		i;
	long	nb;
	int		len;

	nb = n;
	i = 0;
	len = ft_strlen(base);
	ft_bzero(buffer, size);
	if (nb == 0)
		buffer[0] = base[0];
	if (nb < 0)
	{
		buffer[0] = '-';
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		buffer[i] = base[nb % len];
		nb /= len;
		i++;
	}
	return (ft_reverse_buffer(buffer));
}
