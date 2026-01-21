#include "libft/tree.h"

void	ft_DFS_preorder(const t_tree* root, void(*f)(const t_tree*))
{
	if (!root)
		return;
	f(root);
	ft_DFS_preorder(root->left, f);
	ft_DFS_preorder(root->right, f);
}

void	ft_DFS_postorder(const t_tree* root, void(*f)(const t_tree*))
{
	if (!root)
		return;
	ft_DFS_postorder(root->left, f);
	ft_DFS_postorder(root->right, f);
	f(root);
}

void	ft_DFS_inorder(const t_tree* root, void(*f)(const t_tree*))
{
	if (!root)
		return;
	ft_DFS_inorder(root->left, f);
	f(root);
	ft_DFS_inorder(root->right, f);
}

