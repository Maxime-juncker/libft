#include "libft/string.h"
#include "libft/is.h"

#include <stdarg.h>

int		ft_printf(const char *s, ...) {(void)s;return 0;}
int		ft_dprintf(int fd, const char *s, ...) {(void)s; (void)fd; return 0;}


int	parse_arg(const char *str, char *buffer, size_t size, size_t *idx)
{
	const char* options = "csduxXpi%";	
	int			i = 1;	
	int			align[2] = {
					-1, // -1 is left algin 1 is right align
					0 // min width
				};

	if (str[i] == '-' || ft_isdigit(str[i])) // text to align
	{
		i++;
	}

	int option = ft_strfind(options, str[i]);
	if (option == -1)
	{
		return -1;
	}


	return 0;
}

int	add_segment(const char* str, char *buffer, size_t size, size_t* idx)
{
	int		next_arg;
	size_t	buf_len;
	size_t	i;
	int		size_written;

	next_arg = ft_strfind(str, '%');
	buf_len = ft_strlen(buffer);
	i = 0;
	while (str[i] && (i < (size_t)next_arg || next_arg == -1))
	{
		if (buf_len + i < size)
			buffer[buf_len + i] = str[i];
		i++;
	}
	*idx += i;
	size_written = i;
	if (next_arg != -1)
	{
		size_written += parse_arg(str, buffer, size, idx);	
	}
	return size_written;
}

#include <stdio.h>

int	ft_sprintf(char *str, size_t size, const char *format, ...)
{
	size_t	i;
	size_t	str_len;
	va_list	ptr;
	int		total_size;

	va_start(ptr, format);
	i = 0;
	str_len = ft_strlen(format);
	total_size = 0;
	while (i < str_len)
	{
		total_size += add_segment(&format[i], str, size, &i);
	}

	printf("%s\n", str);

	va_end(ptr);
	return total_size;
}

