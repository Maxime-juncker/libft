/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:20:48 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 11:28:21 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/string.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return (ft_strlen(s) + 1);
}
