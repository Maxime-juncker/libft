/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:23:03 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/20 15:31:03 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	break_pos(char *s)
{
	int	i;

	i = 0;
	if (s == NULL || s[0] == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	*cleanup(char **buffer, char **line)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	return (NULL);
}

static char	*dump_buffer(char **buffer, char **line)
{
	char	*new;
	size_t	line_size;

	line_size = ft_strlen(*line) + 1;
	if (break_pos(*buffer) != -1)
	{
		new = malloc(line_size + break_pos(*buffer) + 1);
		if (!new)
			return (cleanup(buffer, line));
		ft_bzero(new, break_pos(*buffer) + 2);
		ft_strlcat(new, *line, line_size + break_pos(*buffer) + 1);
		ft_strlcat(new, *buffer, line_size + break_pos(*buffer) + 1);
		ft_memmove(*buffer, *buffer + break_pos(*buffer) + 1, BUFFER_SIZE);
		cleanup(NULL, line);
		return (new);
	}
	new = malloc(line_size + BUFFER_SIZE);
	if (!new)
		return (cleanup(buffer, line));
	ft_bzero(new, break_pos(*buffer) + 2);
	ft_strlcat(new, *line, line_size + BUFFER_SIZE);
	ft_strlcat(new, *buffer, line_size + BUFFER_SIZE);
	ft_bzero(*buffer, BUFFER_SIZE);
	cleanup(NULL, line);
	return (new);
}

// return -1 (an error) return 1 if \n found return 0 if nothing
// allocate buffer if buffer null
static int	setup_buffer(char **buffer, char **line)
{
	*line = NULL;
	if (!*buffer)
	{
		*buffer = malloc(BUFFER_SIZE + 1);
		ft_bzero(*buffer, BUFFER_SIZE + 1);
	}
	if (!*buffer)
		return (-1);
	*line = dump_buffer(buffer, line);
	if (break_pos(*line) != -1)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			nb_read;

	if (fd <= -1)
		return (NULL);
	if (setup_buffer(&buffer, &line) != 0)
	{
		if (!buffer || !line)
			return (NULL);
		return (line);
	}
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		line = dump_buffer(&buffer, &line);
		if ((nb_read == 0 && line[0] == 0) || !buffer || !line)
			return (cleanup(&buffer, &line));
		if (break_pos(line) != -1 || (nb_read == 0))
			return (line);
		if (nb_read == -1)
			return (cleanup(&buffer, &line));
	}
	return (cleanup(&buffer, &line));
}
