/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:19:09 by mjuncker          #+#    #+#             */
/*   Updated: 2025/10/01 15:35:55 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "ft_printf.h"
#include "libft/memory.h"

int	ft_snprintf(char *buffer, size_t size, const char *format, ...)
{
	int		result;
	va_list	ptr;

	va_start(ptr, format);
	result = ft_vsnprintf(buffer, size, format, &ptr);
	va_end(ptr);
	return (result);
}

int	ft_vsnprintf(char *buffer, size_t size,
	const char *format, va_list *ptr)
{
	int		total_size;
	char	*str;

	str = (char *)format;
	ft_bzero(buffer, size);
	total_size = 0;
	while (*str)
	{
		total_size += add_segment(&str, buffer, size, ptr);
	}
	return (total_size);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ptr;
	char	buffer[2042];

	va_start(ptr, format);
	result = ft_vsnprintf(buffer, sizeof(buffer), format, &ptr);
	va_end(ptr);
	ft_putstr_fd(buffer, 1);
	return (result);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		result;
	va_list	ptr;
	char	buffer[2042];

	va_start(ptr, format);
	result = ft_vsnprintf(buffer, sizeof(buffer), format, &ptr);
	va_end(ptr);
	ft_putstr_fd(buffer, fd);
	return (result);
}
