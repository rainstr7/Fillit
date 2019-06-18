/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2019/02/05 20:20:31 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstaddtoend(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (alst != NULL && new != NULL)
	{
		cur = *alst;
		if (cur != NULL)
		{
			while ((*alst)->next != NULL)
				(*alst) = (*alst)->next;
			(*alst)->next = new;
			*alst = cur;
		}
		else
			(*alst) = new;
	}
}
