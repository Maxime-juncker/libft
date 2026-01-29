#ifndef ARGS_H
#define ARGS_H

#define MAX_ARGS 128

typedef struct s_arg
{
	char		argName;
	const char*	argNameLong;
	const int	hasArg;

}	t_arg;

enum e_hasArg
{
	NO_ARG = 0,
	OPT_ARG,
	REQ_ARG
};

// t_arg*	newArgs();
// int		registerArg(t_arg* args, t_arg newArg);
// void	parseArgs(t_arg* args, int argc, char** argv);

char	ft_getopt(const t_arg* args, int argc, char** argv, char* optarg);

#endif // !ARGS_H
