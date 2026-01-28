#include "libft/tree.h"

t_tree* ft_insertLeft(t_tree* tree, int value)
{
	tree->left = ft_treenew(value);
	tree->left->parent = tree;
	return tree->left;
}

t_tree* ft_insertRight(t_tree* tree, int value)
{
	tree->right = ft_treenew(value);
	tree->right->parent = tree;
	return tree->right;
}

