/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2018/11/20 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hst, const char *needle)
{
	int		i;
	size_t	n;
	size_t	h;

	n = ft_strlen(needle);
	h = ft_strlen(hst);
	i = 0;
	while (hst[i] != '\0')
	{
		if (hst[i] == *needle && ft_strncmp((hst + i), needle, n) == 0)
		{
			return (((char *)(hst + i)));
		}
		else if (n == 0)
			return ((char *)hst);
		i++;
	}
	if (n == 0 && h == 0)
		return (((char *)hst));
	else
		return ((void *)0);
}
