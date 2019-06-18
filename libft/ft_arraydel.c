/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2019/02/04 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_arraydel(size_t len, void ***array)
{
	size_t	i;

	i = 0;
	if (array != NULL)
	{
		i = 0;
		while (i < len)
		{
			if ((*array)[i] != NULL)
				free((*array)[i]);
			i++;
		}
		if (*array != NULL)
			free(*array);
	}
}
