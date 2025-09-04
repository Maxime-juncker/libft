#include "libft/string.h"

static int	get_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= '\t' && s[*i] <= '\r'))
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int in_base(char c, char* base, int base_len)
{
	int i = 0;
	while (base[i] && i < base_len)
	{
		if (base[i] == c)
			return i;
		i++;
	}
	return -1;
}

long ft_strtol(const char* nptr, char** endptr, int base)
{
	char	b[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	long	n = 0;
	int		i = 0;
	int		sign = get_sign(nptr, &i);

	int tmp;
	while ((tmp = in_base(ft_toupper(nptr[i]), b, base)) != -1)
	{
		n *= base;
		n += tmp;
		i++;
	}
	*endptr = (char*)(&nptr[i]);
	n *= sign;
	return n;
}
