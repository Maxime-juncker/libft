/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:36:40 by mjuncker          #+#    #+#             */
/*   Updated: 2025/09/08 09:59:08 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/is.h"
#include "libft/math.h"

static int	get_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	while (ft_iswhitespace(s[*i]))
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	int		i;
	double	res;
	int		sign;
	int		dot_start;

	res = 0;
	i = 0;
	sign = get_sign(nptr, &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
	{
		dot_start = i;
		i++;
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			res += (nptr[i] - '0') / (float)ft_pow(10, ((float)i - dot_start));
			i++;
		}
	}
	*endptr = (char *)&nptr[i];
	return (res * sign);
}
