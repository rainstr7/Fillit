/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:35:21 by cmaggio           #+#    #+#             */
/*   Updated: 2018/12/20 19:36:35 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	next = *alst;
	*alst = NULL;
	while (next != NULL)
	{
		current = next;
		next = current->next;
		del(current->content, current->content_size);
		ft_memdel((void *)&current);
		current = NULL;
	}
}
