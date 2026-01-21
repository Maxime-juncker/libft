#include "libft/tree.h"
#include "libft/memory.h"
#include <stdlib.h>

t_tree*	ft_treenew(int value)
{
	t_tree* tree = malloc(sizeof(t_tree));
	if (!tree)
		return NULL;
	ft_bzero(tree, sizeof(t_tree));
	tree->value = value;
	
	return tree;
}
