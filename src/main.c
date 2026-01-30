#include <stdio.h>
#include "libft/args.h"

int main(int argc, char** argv)
{
	const t_arg args[] = {
		(t_arg){ .argName = 'b', .argNameLong = "len", .hasArg = REQ_ARG },
		(t_arg){ .argName = 'a', .argNameLong = "arrow", .hasArg = NO_ARG },
		(t_arg){ .argName = 0, .argNameLong = NULL, .hasArg = 0 }, // end option
	};

	int c;
	char* optarg = NULL;
	while ((c = ft_getopt(args, argc, argv, &optarg)) != -1)
	{
		switch (c)
		{
			case 'a':
				printf("option a ok %s\n", optarg);
				break;
			case 'b':
				printf("option b ok %s\n", optarg);
				break;
			default:
				printf("default\n");
				break;
		
		}

	}
}
