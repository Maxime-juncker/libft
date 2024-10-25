/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:04:13 by mjuncker          #+#    #+#             */
/*   Updated: 2024/10/24 17:51:27 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_nb_len(int n)
{
	size_t		i;
	long int	nb;

	nb = (long)n;
	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb / 10 > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*res;
	size_t		i;
	size_t		len;

	len = get_nb_len(n);
	nb = (long)n;
	res = malloc(len + 1);
	i = 0;
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb > 0)
	{
		res[len - i++ - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	res[len] = '\0';
	return (res);
}
