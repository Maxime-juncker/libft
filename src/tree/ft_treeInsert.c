#include "libft/tree.h"
#include "libft/string.h"
#include <stdio.h>

t_tree* ft_insertLeft(t_tree* tree, int value)
{
	tree->left = ft_treenew(value);
	return tree->left;
}

t_tree* ft_insertRight(t_tree* tree, int value)
{
	tree->right = ft_treenew(value);
	return tree->right;
}

t_tree* ft_insertBST(t_tree* root, int value)
{
	if (!root)
		return ft_treenew(value);

	if (root->value > value)
	{
		root->left = ft_insertBST(root->left, value);
	}
	else if (root->value < value)
	{
		root->right = ft_insertBST(root->right, value);
	}
	return root;
}

int	ft_searchBST(t_tree* root, int key)
{
	if (!root)
		return 0;
	if (root->value == key)
		return 1;

	if (root->value > key)
	{
		return ft_searchBST(root->left, key);
	}
	else if (root->value < key)
	{
		return ft_searchBST(root->right, key);
	}

	return 0;
}

void ft_printTree_step(const char* prefix, const t_tree* root, int isLeft)
{
	if (!root)
		return;

	printf("%s%s", prefix, isLeft ? "|--" : "L--");
	printf("%d\n", root->value);

	const char* newPrefix = ft_strjoin((char*)prefix, isLeft ? "|  " : "   ");
	ft_printTree_step(newPrefix, root->left, 1);
	ft_printTree_step(newPrefix, root->right, 0);
}

void ft_printTree(const t_tree* root)
{
	ft_printTree_step("", root, 0);
}

