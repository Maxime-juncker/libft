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
#include "libft/math.h"

char	*ft_itoa(char *buffer, size_t size, int n)
{
	return (ft_itoa_base(buffer, size, n, "0123456789"));
}

char	*ft_uitoaddr(char *buffer, size_t size, unsigned long long n)
{
	ft_strlcat(buffer, "0x", size);
	ft_uitoa_base(buffer + 2, size, n, "0123456789abcdef");
	return buffer;
}

char	*ft_uitoa(char *buffer, size_t size, unsigned int n)
{
	return (ft_uitoa_base(buffer, size, n, "0123456789"));
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
	while (nb != 0)
	{
		buffer[i] = base[ft_abs(nb % len)];
		nb /= len;
		i++;
	}
	if (n < 0)
		buffer[i] = '-';
	return (ft_reverse_buffer(buffer));
}

char	*ft_uitoa_base(char *buffer, size_t size, unsigned int n, const char *base)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(base);
	ft_bzero(buffer, size);
	if (n == 0)
		buffer[0] = base[0];
	while (n > 0)
	{
		buffer[i] = base[n % len];
		n /= len;
		i++;
	}
	return (ft_reverse_buffer(buffer));
}
