/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:40:52 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 11:58:00 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

static size_t	arrlen(void **arr)
{
	size_t	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_arrsort(char **arr)
{
	int		i;
	int		diff;
	char	*temp;
	int		size;

	diff = 1;
	size = arrlen((void **)arr);
	while (diff)
	{
		i = 0;
		diff = 0;
		while (i < (size - 1))
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				diff = 1;
			}
			i++;
		}
	}
}
