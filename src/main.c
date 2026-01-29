#include <stdio.h>
#include "libft/args.h"

int main(int argc, char** argv)
{
	const t_arg args[] = {
		(t_arg){ .argName = 'l', .argNameLong = "count", .hasArg = NO_ARG },
		(t_arg){ .argName = 'a', .argNameLong = "count", .hasArg = NO_ARG },
		(t_arg){ .argName = 0, .argNameLong = NULL, .hasArg = 0 }, // end option
	};

	int c;
	while ((c = ft_getopt(args, argc, argv, NULL)) != -1)
	{
		switch (c)
		{
			case 'a':
				printf("option a ok\n");
				break;
			case 'l':
				printf("option b ok\n");
				break;
			default:
				printf("default\n");
				break;
		
		}

	}
}
