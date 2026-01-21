#include "libft/tree.h"
#include <stdio.h>

void step(const t_tree* tree)
{
	printf("%c, ", tree->value);
}

int main()
{
	t_tree* root = ft_treenew('f');
	ft_insertLeft(root, 'b');
	ft_insertLeft(root->left, 'a');
	ft_insertRight(root->left, 'd');
	ft_insertLeft(root->left->right, 'c');
	ft_insertRight(root->left->right, 'e');
	ft_insertRight(root, 'g');
	ft_insertRight(root->right, 'i');
	ft_insertLeft(root->right->right, 'h');
	ft_printTree(root);

	ft_DFS_preorder(root, &step);
	printf("\n");
	ft_DFS_postorder(root, step);
	printf("\n");
	ft_DFS_inorder(root, step);

}
