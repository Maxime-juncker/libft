/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:26:23 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/19 12:22:08 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*nb;
	int		len;

	nb = ft_itoa(n);
	len = ft_strlen(nb);
	while (len > 0)
	{
		ft_putchar_fd(nb[ft_strlen(nb) - len], fd);
		len--;
	}
	len = ft_strlen(nb);
	free(nb);
	return (len);
}

void	ft_putnbr_hex(unsigned long int nbr, char *base, int fd, int *count)
{
	if (nbr / 16 > 0)
	{
		ft_putnbr_hex(nbr / 16, base, fd, count);
		(*count)++;
		ft_putnbr_hex((nbr % 16), base, fd, count);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

int	ft_putaddr(long int nbr, char *base, int fd)
{
	int	count;

	count = 2;
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(nbr, base, fd, &count);
	return (count);
}
