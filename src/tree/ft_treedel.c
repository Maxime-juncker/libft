#include "libft/tree.h"

t_tree* getSuccessor(t_tree* tree)
{
	tree = tree->right;
	while(tree && tree->left)
	{
		tree = tree->left;
	}
	return tree;
}

t_tree* ft_treedel(t_tree* root, int key)
{
	if (!root)
		return root;

	if (root->value > key)
		root->left = ft_treedel(root->left, key);
	if (root->value < key)
		root->right = ft_treedel(root->right, key);

}
