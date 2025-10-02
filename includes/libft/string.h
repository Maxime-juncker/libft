/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:16:33 by mjuncker          #+#    #+#             */
/*   Updated: 2025/10/01 14:18:33 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>

# define FREE1 0b0001
# define FREE2 0b0010

void	ft_generic_sort(void **arr, size_t lenght, int(*f)(void*, void*));

// string convertions
int		ft_atoi(const char *nptr);
char	*ft_dtoa(char *buffer, size_t size, double d, int precision);
char	*ft_atos(char **arr, char separator);
char	*ft_itoa(char *buffer, size_t size, int n);
char	*ft_itoa_base(char *buffer, size_t size, int n, const char *base);
char	*ft_uitoa(char *buffer, size_t size, unsigned int n);
char	*ft_uitoa_base(char *buffer, size_t size, unsigned long n,
			const char *base);
char	*ft_uitoaddr(char *buffer, size_t size, void *ptr);
long	ft_strtol(const char *nptr, char **endptr, int base);
double	ft_strtod(const char *nptr, char **endptr);

// string math
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);

// string manipulation
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_reverse_buffer(char *buffer);

// string allocation
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char *s2, const int flags);
char	*ft_charjoin(char *s1, char const c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

// string search
int		ft_strfind(const char *str, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

// string parsing
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
