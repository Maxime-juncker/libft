#include "libft/args.h"
#include <stdlib.h>

static const t_arg* findLongOption(const t_arg* args, const char* arg)
{
	(void)args;
	(void)arg;
	return NULL;
}

static const t_arg* findOption(const t_arg* args, const char* arg, int* idx)
{
	int i = 0;
	static int j = 0;

	while (args[i].argName)
	{
		if (arg[j] == args[i].argName) // found arg
		{
			j++;
			if (!arg[j])
			{
				j = 0;
				*idx += 1;
			}
			return &args[i];
		}
		i++;
	}

	return NULL;
}


static const t_arg* parseArg(const t_arg* args, const char* arg, int* idx)
{
	int i = 0;
	while (i <= 2 && arg[i] && arg[i] == '-')
		i++;
	
	if (i == 2)
	{
		*idx += 1;
		return findLongOption(args, arg + 2);
	}
	else if (i == 1)
	{
		return findOption(args, arg + 1, idx);
	}

	return NULL; // not an option
}

char	ft_getopt(const t_arg* args, int argc, char** argv, char* optarg)
{
	(void)optarg;
	static int i = 1;

	if (i >= argc)
		return -1;

	const char* arg = argv[i];

	const t_arg* opt = parseArg(args, arg, &i);
	if (!opt)
		return -1;

	return opt->argName;
}
