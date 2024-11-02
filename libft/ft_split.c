/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:42:45 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/02 19:13:35 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_nb_split(char const *s, char c)
{
	size_t		i;
	size_t		n;
	short int	new;

	n = 0;
	i = 0;
	new = 1;
	while (s[i])
	{
		if (s[i] != c && new)
		{
			n++;
			new = 0;
		}
		else if (s[i] == c)
			new = 1;
		i++;
	}
	return (n);
}

size_t	get_split_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

void	cleanup(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	result = malloc((get_nb_split(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[0])
	{
		while (s[0] == c && s[0])
			s++;
		if (get_split_len(s, c) == 0)
			break ;
		result[y] = malloc(get_split_len(s, c) + 1);
		if (result[y] == NULL)
			cleanup(result, y);
		i = 0;
		while (s[0] != c && s[0])
			result[y][i++] = s++[0];
		result[y++][i] = '\0';
	}
	result[y] = NULL;
	return (result);
}
