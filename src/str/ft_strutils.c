int	ft_strfind(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return i;
		i++;
	}
	return -1;
}
