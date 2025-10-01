/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:26:23 by mjuncker          #+#    #+#             */
/*   Updated: 2025/10/01 15:37:59 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/string.h"

int	ft_putnbr_fd(int fd, int n)
{
	return (ft_putnbr_base_fd(fd, n, "0123456789"));
}

int	ft_putnbr_base_fd(int fd, int n, const char *base)
{
	char	buffer[64];

	ft_itoa_base(buffer, sizeof(buffer), n, base);
	return (ft_putstr_fd(buffer, fd));
}

char	*ft_reverse_buffer(char *buffer)
{
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(buffer);
	i = 0;
	while (i < len / 2)
	{
		tmp = buffer[i];
		buffer[i] = buffer[len - 1 - i];
		buffer[len - 1 - i] = tmp;
		i++;
	}
	return (buffer);
}

int	ft_putaddr(long int nbr, char *base, int fd)
{
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_base_fd(fd, nbr, base) + 2);
}
