#include "libft/tree.h"
#include "libft/vector.h"
#include <stdio.h>
#include <stdlib.h>

void step(const t_tree* tree)
{
	printf("%c, ", tree->value);
}

void clean(const t_tree* tree)
{
	free((void*)tree);
}

int main()
{
	t_vector vec = newVec(2);

	printVec(&vec);

	for (int i = 1; i < 15; i++)
	{
		vecPush(&vec, i);
		printVec(&vec);
	}
	for (int i = 1; i < 15; i++)
	{
		printf("%d, ", vecPop(&vec));
	}

	freeVec(&vec);
	printVec(&vec);

	vecPush(&vec, 10);
	printVec(&vec);
	freeVec(&vec);
}
