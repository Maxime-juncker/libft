/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:00:17 by mjuncker          #+#    #+#             */
/*   Updated: 2025/09/08 09:57:23 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/is.h"

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

static int	in_base(char c, const char *base, int base_len)
{
	int	i;

	i = 0;
	while (base[i] && i < base_len)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	const char	b[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	long		n;
	int			i;
	int			sign;
	int			tmp;

	n = 0;
	i = 0;
	sign = get_sign(nptr, &i);
	tmp = in_base(ft_toupper(nptr[i]), b, base);
	while (tmp != -1)
	{
		n *= base;
		n += tmp;
		i++;
		tmp = in_base(ft_toupper(nptr[i]), b, base);
	}
	*endptr = (char *)(&nptr[i]);
	n *= sign;
	return (n);
}
