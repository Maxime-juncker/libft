#include "libft/io.h"
#include "libft/tree.h"
#include "libft/string.h"

void ft_printTree_step(const char* prefix, const t_tree* root, int isLeft)
{
	if (!root)
		return;

	ft_printf("%s%s", prefix, isLeft ? "|--" : "L--");
	ft_printf("%d\n", root->value);

	const char* newPrefix = ft_strjoin((char*)prefix, isLeft ? "|  " : "   ");
	ft_printTree_step(newPrefix, root->left, 1);
	ft_printTree_step(newPrefix, root->right, 0);
	free((char*)newPrefix);
}

void ft_printTree(const t_tree* root)
{
	ft_printTree_step("", root, 0);
}

void ft_printNode(const t_tree* node)
{
	if (!node)
	{
		ft_printf("(null)");
		return ;
	}

	ft_printf("%p: %d (left: %p) (right: %p)\n",
		   node, node->value, node->left, node->right);
}
