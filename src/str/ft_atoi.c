/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:28:20 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 11:25:25 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

static int	check_overflow(long n, int sign)
{
	if (n * 10 / 10 != n)
	{
		if (sign < 0)
			return (0);
		return (-1);
	}
	return (2);
}

static int	get_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= '\t' && s[*i] <= '\r'))
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	n = 0;
	sign = get_sign(nptr, &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (check_overflow(n, sign) != 2)
			return (check_overflow(n, sign));
		n *= 10;
		n += nptr[i] - '0';
		i++;
	}
	n *= sign;
	return ((int)n);
}
