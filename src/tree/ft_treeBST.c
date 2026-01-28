#include "libft/tree.h"
#include <stdio.h>
#include <stdlib.h>

t_tree* ft_insertBST(t_tree* root, int value, t_tree* parent)
{
	if (!root)
	{
		t_tree* tree = ft_treenew(value);
		tree->parent = parent;
		return tree;
	}

	if (root->value > value)
	{
		root->left = ft_insertBST(root->left, value, root);
	}
	else if (root->value < value)
	{
		root->right = ft_insertBST(root->right, value, root);
	}
	return root;
}

int		ft_inTree(t_tree* root, int key)
{
	return ft_searchBST(root, key) ? 1 : 0;
}

t_tree*	ft_searchBST(t_tree* root, int key)
{
	if (!root)
		return NULL;
	if (root->value == key)
		return root;

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

t_tree* ft_minimumBST(t_tree* root)
{
	while (root->left)
		root = root->left;
	return root;
}

t_tree* ft_maximumBST(t_tree* root)
{
	while (root->right)
		root = root->right;
	return root;
}

/// find the smallest node that's bigger than root value
t_tree* ft_successorBST(t_tree* root)
{
	if (root->right)
	{
		return ft_minimumBST(root->right);
	}

	t_tree* parent = root->parent;
	while (parent && root == parent->right)
	{
		root = parent;
		parent = parent->parent;
	}
	return parent;
}

// t_tree*	ft_predecesorBST(t_tree* root)
// {
// 	if (root->left)
// 		return ft_maximumBST(root->left);
//
// }
