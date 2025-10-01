/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:33:23 by mjuncker          #+#    #+#             */
/*   Updated: 2025/10/01 15:35:37 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_segment
{
	char	buffer[1024];
	char	*backup_buf;
	short	side;
	int		min_width;
	char	c;
}	t_segment;

int	add_option(t_segment *seg, char **str, va_list *ptr);
int	add_segment(char **str, char *buffer, size_t size, va_list *ptr);

#endif
