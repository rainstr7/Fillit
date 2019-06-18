/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2019/02/05 20:22:32 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_del(void *content, size_t size)
{
	ft_memset(content, 0, size);
	ft_memdel(&content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*new_lst;
	t_list	*new_node;

	node = lst;
	new_lst = NULL;
	new_node = NULL;
	if (f != NULL)
	{
		while (node != NULL)
		{
			if ((new_node = f(ft_lstnew(node->content, node->content_size))))
			{
				ft_lstaddtoend(&new_lst, new_node);
				node = node->next;
				new_node = NULL;
			}
			else
				ft_lstdel(&new_lst, &ft_del);
		}
	}
	return (new_lst);
}
