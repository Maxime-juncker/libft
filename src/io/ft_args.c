#include "libft/args.h"
#include "libft/string.h"
#include <stdio.h>

typedef struct s_argPos
{
	int i;
	int j;

}	t_argPos;

static int isArgValid(const t_arg arg)
{
	return arg.argName || arg.argNameLong;
}

static char* getOptarg(const int argc, char** argv, t_argPos* pos)
{


}

static const t_arg* findLongOption(const t_arg* args, const char* arg)
{
	int i = 0;
	while (isArgValid(args[i]))
	{
		if (ft_strcmp(args[i].argNameLong, arg) == 0)
			return &args[i];
		i++;
	}
	return NULL;
}


static const t_arg* findOption(const t_arg* args, const char* arg, t_argPos* pos)
{
	int i = 0;

	while (isArgValid(args[i]))
	{
		if (arg[pos->j] == args[i].argName) // found arg
		{
			pos->j++;
			if (!arg[pos->j])
			{
				pos->j = 0;
				pos->i++;
			}
			return &args[i];
		}
		i++;
	}

	return NULL;
}


static const t_arg* parseArg(const t_arg* args, const char* arg, t_argPos* pos)
{
	int i = 0;
	while (i <= 2 && arg[i] && arg[i] == '-')
		i++;
	
	if (i == 2)
	{
		pos->i++;
		return findLongOption(args, arg + 2);
	}
	else if (i == 1)
	{
		return findOption(args, arg + 1, pos);
	}

	return NULL; // not an option
}

char	ft_getopt(const t_arg* args, int argc, char** argv, char** optarg)
{
	static t_argPos pos = { .i = 1, .j = 0 };

	if (pos.i >= argc)
		return -1;

	const char* arg = argv[pos.i];

	const t_arg* opt = parseArg(args, arg, &pos);
	if (!opt)
		return -1;

	char* tmp = getOptarg(argc, argv, &pos);
	if (opt->hasArg == REQ_ARG && tmp == NULL)
	{
		printf("%s: option '%s' requires an argument\n", argv[0], args->argNameLong);
	}

	if (optarg)
		*optarg = tmp;

	return opt->argName;
}
