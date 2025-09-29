#include "libft/string.h"
#include "libft/is.h"

#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *s, ...) {(void)s;return 0;}
int		ft_dprintf(int fd, const char *s, ...) {(void)s; (void)fd; return 0;}

int	add_num(char opt, char *buffer, size_t size, va_list *ptr)
{
	char	tmp_buf[128];

	if (opt == 'd' || opt == 'i')
	{
		ft_itoa(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int));
		return ft_strlcat(buffer, tmp_buf, size);
	}
	if (opt == 'u')
	{
		ft_uitoa(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, unsigned int));
		return ft_strlcat(buffer, tmp_buf, size);
	}
	if (opt == 'x')
	{
		ft_itoa_base(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int),
			   "0123456789abcdef");
		return ft_strlcat(buffer, tmp_buf, size);
	}
	if (opt == 'X')
	{
		ft_itoa_base(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int),
			   "0123456789ABCDEF");
		return ft_strlcat(buffer, tmp_buf, size);
	}
	if (opt == 's')
		return ft_strlcat(buffer, va_arg(*ptr, char*), size);
	return -1;
}

int	parse_arg(char **str, char *buffer, size_t size, va_list *ptr)
{
	const char options[] = "dXxuiscp%";	
	char		tmp_buf[128] = {0};
	int			buf_len;
	int			align[2] = {
					-1, // -1 is left algin 1 is right align
					0 // min width
				};

	if (**str == '-' || ft_isdigit(**str)) // text to align
	{
		*str += 1;
	}

	int opt_i = ft_strfind(options, (*str)[1]);
	if (opt_i == -1)
		return -1;

	buf_len = ft_strlen(buffer);
	if (opt_i <= 5)
		add_num(options[opt_i], buffer, size, ptr);
	if (options[opt_i] == 'c')
		buffer[buf_len] = va_arg(*ptr, int);

	*str += 2;
	return ft_strlen(buffer) - buf_len;
}

int	add_segment(char** str, char *buffer, size_t size, va_list* ptr)
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
	return size_written;
}

#include <stdio.h>

int	ft_sprintf(char *buffer, size_t size, const char *format, ...)
{
	va_list	ptr;
	int		total_size;
	char	*str;

	va_start(ptr, format);
	str = (char*)format;
	total_size = 0;
	while (*str)
	{
		total_size += add_segment(&str, buffer, size, &ptr);
	}

	printf("%s\n", buffer);

	va_end(ptr);
	return total_size;
}

