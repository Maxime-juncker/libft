/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:18:55 by mjuncker          #+#    #+#             */
/*   Updated: 2025/10/01 15:35:09 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/is.h"
#include "libft/memory.h"
#include "libft/math.h"
#include "ft_printf.h"

static int	add_to_buffer(t_segment *seg, char *buffer,
						size_t size, int total_size)
{
	size_t	buf_len;
	int		i;

	buf_len = ft_strlen(buffer);
	if (seg->side == 1)
	{
		ft_strlcat(buffer, seg->buffer, size);
		buf_len = ft_strlen(buffer);
	}
	i = 0;
	while (i + ft_strlen(seg->buffer) < (size_t)ft_abs(seg->min_width))
	{
		buffer[buf_len + i] = seg->c;
		total_size++;
		i++;
	}
	if (seg->side == 0)
		ft_strlcat(buffer, seg->buffer, size);
	return (total_size);
}

static void	set_align(char **str, t_segment *seg)
{
	if (**str == '-' || ft_isdigit(**str))
	{
		if (**str == '0' || (**str == '-' && *(*str + 1) == '0'))
		{
			*str += 1;
			seg->c = '0';
		}
		else
			seg->c = ' ';
		seg->min_width = ft_atoi(*str);
		if (seg->min_width < 0)
		{
			seg->side = 1;
			*str += 1;
		}
		while (ft_isdigit(**str))
			*str += 1;
	}
}

static int	parse_arg(char **str, char *buffer, size_t size, va_list *ptr)
{
	t_segment		seg;
	int				total_size;

	ft_bzero(&seg, sizeof(t_segment));
	total_size = 0;
	*str += 1;
	set_align(str, &seg);
	total_size = add_option(&seg, str, ptr);
	*str += 1;
	return (add_to_buffer(&seg, buffer, size, total_size));
}

int	add_segment(char **str, char *buffer, size_t size, va_list *ptr)
{
	int		next_arg;
	size_t	buf_len;
	size_t	i;
	int		size_written;

	next_arg = ft_strfind(*str, '%');
	buf_len = ft_strlen(buffer);
	i = 0;
	while ((*str)[i] && (i < (size_t)next_arg || next_arg == -1))
	{
		if (buf_len + i < size)
			buffer[buf_len + i] = (*str)[i];
		i++;
	}
	size_written = i;
	*str += i;
	if (next_arg != -1)
	{
		size_written += parse_arg(str, buffer, size, ptr);
	}
	return (size_written);
}
