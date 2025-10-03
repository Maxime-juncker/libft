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

static int	print_level(int level)
{
	const char	*msg[] = {"Log", "Debug", "Warning", "Error", "Alert"};
	const char	*col[] = {BLUE, PURPLE, YELLOW, RED, B_RED};
	int			fd;

	if (level <= 1)
		fd = 1;
	else
		fd = 2;
	if ((size_t)level < sizeof(msg))
		ft_dprintf(fd, "[%s%-7s%s]: ", col[level], msg[level], RESET);
	else
		ft_dprintf(fd, "[%-7s]: ", "Unknow");
	return (fd);
}

int	ft_debug(int level, const char *format, ...)
{
	int		result;
	va_list	ptr;
	char	buffer[2042];
	int		fd;

	fd = print_level(level);
	va_start(ptr, format);
	result = ft_vsnprintf(buffer, sizeof(buffer), format, &ptr);
	va_end(ptr);
	ft_putendl_fd(buffer, fd);
	return (result);
}
