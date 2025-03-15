/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:51:52 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 14:57:30 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"

void	alert(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s[ALERT]: %s%s\n", B_RED, RESET, msg);
}

void	info(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s[LOG]: %s%s\n", GRAY, RESET, msg);
}

void	warning(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s[WARNING]: %s%s\n", YELLOW, RESET, msg);
}

void	error(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s[ERROR]: %s%s\n", RED, RESET, msg);
}

void	success(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s[SUCCESS]: %s%s\n", GREEN, RESET, msg);
}
