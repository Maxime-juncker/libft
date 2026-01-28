#ifndef  TREE_H
# define TREE_H

typedef struct s_tree
{
	struct s_tree*	left;
	struct s_tree*	right;
	struct s_tree*	parent;

	int				value;
}	t_tree;


t_tree*	ft_treenew(int value);

t_tree* ft_insertLeft(t_tree* tree, int value);
t_tree*	ft_insertRight(t_tree* tree, int value);

t_tree* ft_insertBST(t_tree* root, int value, t_tree* parent);
t_tree*	ft_searchBST(t_tree* root, int key);
int		ft_inTree(t_tree* root, int key);

void	ft_printTree(const t_tree* root);
void	ft_printNode(const t_tree* node);

t_tree* ft_successorBST(t_tree* root);

/** go in depth first search (pre order) and call f for all nodes*/
void	ft_DFS_preorder(const t_tree* root, void(*f)(const t_tree*));
void	ft_DFS_postorder(const t_tree* root, void(*f)(const t_tree*));
void	ft_DFS_inorder(const t_tree* root, void(*f)(const t_tree*));
#endif
