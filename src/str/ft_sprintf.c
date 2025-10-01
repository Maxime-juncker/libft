#include "libft/io.h"
#include "libft/string.h"
#include "libft/is.h"
#include "libft/memory.h"
#include "libft/math.h"

#include <stdarg.h>
#include <stdio.h>

typedef struct s_segment
{
	char	buffer[1024];
	char	*backup_buf;
	short	side;
	int		min_width;
	char	c;
}	t_segment;

int		ft_printf(const char *s, ...) {(void)s;return 0;}
int		ft_dprintf(int fd, const char *s, ...) {(void)s; (void)fd; return 0;}

int	add_option_text(char opt, char *buffer, size_t size, va_list *ptr)
{
	char	tmp_buf[128] = {0};

	if (opt == 'p')
	{
		printf("\n");
		ft_uitoaddr(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, void*));
		return ft_strlcat(buffer, tmp_buf, size);
	}
	if (opt == 's')
		return ft_strlcat(buffer, va_arg(*ptr, char*), size);
	if (opt == 'c')
	{
		buffer[ft_strlen(buffer)] = va_arg(*ptr, int);
		return ft_strlen(buffer) + 1;
	}
	if (opt == 'f')
	{
		ft_dtoa(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, double));
		return ft_strlcat(buffer, tmp_buf, size);
	}
	return -1;
}

int	add_option_num(char opt, char *buffer, size_t size, va_list *ptr)
{
	char	tmp_buf[128] = {0};

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
		ft_uitoa_base(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int),
			   "0123456789abcdef");
		return ft_strlcat(buffer, tmp_buf, size);
	}
	if (opt == 'X')
	{
		ft_uitoa_base(tmp_buf, sizeof(tmp_buf), va_arg(*ptr, int),
			   "0123456789ABCDEF");
		return ft_strlcat(buffer, tmp_buf, size);
	}
	return -1;
}

int	parse_arg(char **str, char *buffer, size_t size, va_list *ptr)
{
	const char		options[] = "dXxuiscpf%";	
	int				buf_len;
	t_segment		seg;
	ft_bzero(&seg, sizeof(t_segment));

	*str += 1; // skip %
	buf_len = ft_strlen(buffer);
	if (**str == '-' || ft_isdigit(**str)) // text to align
	{
		seg.min_width = ft_atoi(*str);
		if (seg.min_width < 0)
		{
			seg.side = 1;
			*str += 1;
		}
		while (ft_isdigit(**str))
			*str += 1;
	}

	int opt_i = ft_strfind(options, **str);
	if (opt_i == -1)
		return -1;

	if (opt_i <= 4)
		add_option_num(options[opt_i], seg.buffer, sizeof(seg.buffer), ptr);
	else
		add_option_text(options[opt_i], seg.buffer, sizeof(seg.buffer), ptr);

	if (seg.side == 1)
	{
		ft_strlcat(buffer, seg.buffer, size);
		buf_len = ft_strlen(buffer);
	}
	for (int i = 0; i + ft_strlen(seg.buffer) < (size_t)ft_abs(seg.min_width); i++)
	{
		buffer[buf_len + i] = ' ';
	}
	if (seg.side == 0)
		ft_strlcat(buffer, seg.buffer, size);

	*str += 1;
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

