/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:51:52 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 12:17:50 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"

void	alert(const char *msg)
{
	ft_dprintf(2, "%s[ALERT]: %s%s\n", B_RED, RESET, msg);
}

void	info(const char *msg)
{
	ft_dprintf(2, "%s[LOG]: %s%s\n", GRAY, RESET, msg);
}

void	warning(const char *msg)
{
	ft_dprintf(2, "%s[WARNING]: %s%s\n", YELLOW, RESET, msg);
}

void	error(const char *msg)
{
	ft_dprintf(2, "%s[ERROR]: %s%s\n", RED, RESET, msg);
}

void	success(const char *msg)
{
	ft_dprintf(2, "%s[SUCCESS]: %s%s\n", GREEN, RESET, msg);
}
