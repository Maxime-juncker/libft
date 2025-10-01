#include "libft/string.h"

char	*ft_dtoa(char *buffer, size_t size, double d)
{
	long	dec;
	double	fract;
	char	buff[1024];

	dec = (long)d;
	fract = d - dec;
	while (fract != (long)fract)
	{
		fract *= 10;
	}

	ft_itoa(buff, sizeof(buff), dec);
	ft_strlcat(buffer, buff, size);
	ft_strlcat(buffer, ".", size);
	ft_itoa(buff, sizeof(buff), fract);
	ft_strlcat(buffer, buff, size);

	return buffer;
}
