/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:30:58 by mjuncker          #+#    #+#             */
/*   Updated: 2025/10/01 15:36:13 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/memory.h"
#include "libft/string.h"

static int	add_option02(char opt, char *buffer, size_t size, va_list *ptr)
{
	char	tmp_buf[128];

	ft_bzero(tmp_buf, sizeof(tmp_buf));
	if (opt == 'p')
	{
		ft_uitoaddr(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, void *));
		return (ft_strlcat(buffer, tmp_buf, size));
	}
	if (opt == 's')
		return (ft_strlcat(buffer, va_arg(*ptr, char *), size));
	if (opt == 'c')
	{
		buffer[ft_strlen(buffer)] = va_arg(*ptr, int);
		return (ft_strlen(buffer) + 1);
	}
	if (opt == 'f')
	{
		ft_dtoa(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, double), 3);
		return (ft_strlcat(buffer, tmp_buf, size));
	}
	return (-1);
}

static int	add_option03(char opt, char *buffer, size_t size, va_list *ptr)
{
	char	tmp_buf[128];

	ft_bzero(tmp_buf, sizeof(tmp_buf));
	if (opt == 'd' || opt == 'i')
	{
		ft_itoa(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int));
		return (ft_strlcat(buffer, tmp_buf, size));
	}
	if (opt == 'u')
	{
		ft_uitoa(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, unsigned int));
		return (ft_strlcat(buffer, tmp_buf, size));
	}
	return (-1);
}

static int	add_option01(char opt, char *buffer, size_t size, va_list *ptr)
{
	char	tmp_buf[128];

	ft_bzero(tmp_buf, sizeof(tmp_buf));
	if (opt == 'x')
	{
		ft_uitoa_base(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int),
			"0123456789abcdef");
		return (ft_strlcat(buffer, tmp_buf, size));
	}
	if (opt == 'X')
	{
		ft_uitoa_base(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int),
			"0123456789ABCDEF");
		return (ft_strlcat(buffer, tmp_buf, size));
	}
	return (-1);
}

int	add_option(t_segment *seg, char **str, va_list *ptr)
{
	const char		options[] = "diuXxscpf%";	
	int				opt_i;
	int				total_size;

	total_size = -1;
	opt_i = ft_strfind(options, **str);
	if (opt_i == -1)
		return (-1);
	if (opt_i <= 2)
		total_size = add_option03(options[opt_i],
				seg->buffer, sizeof(seg->buffer), ptr);
	else if (opt_i <= 4)
		total_size = add_option01(options[opt_i],
				seg->buffer, sizeof(seg->buffer), ptr);
	else
		total_size = add_option02(options[opt_i],
				seg->buffer, sizeof(seg->buffer), ptr);
	return (total_size);
}
