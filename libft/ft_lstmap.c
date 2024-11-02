/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:11:12 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/02 19:13:57 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	while (lst)
	{
		ft_lstadd_back(&map, ft_lstnew(f(lst->content)));
		if (!ft_lstlast(map))
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (map);
}