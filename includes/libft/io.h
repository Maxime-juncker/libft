/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:15:47 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/15 10:05:08 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <unistd.h>

// colors
# define RESET	"\033[0m"
# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"
# define GRAY	"\033[0;30m"

// Background
# define B_BLACK	"\033[40m"
# define B_RED		"\033[41m"
# define B_GREEN	"\033[42m"
# define B_YELLOW	"\033[43m"
# define B_BLUE		"\033[44m"
# define B_PURPLE	"\033[45m"
# define B_CYAN		"\033[46m"
# define B_WHITE	"\033[47m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// debug.c
void	success(const char *msg);
void	warning(const char *msg);
void	error(const char *msg);
void	alert(const char *msg);
void	info(const char *msg);

// put function
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_hex(unsigned long int nbr, char *base, int fd);
int		ft_putaddr(long int nbr, char *base, int fd);

// printf functions
int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);

// assestions
int		malloc_assert(void *mem, const char *file,
			int line, const char *function);

#endif
