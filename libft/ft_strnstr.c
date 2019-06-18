/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2018/11/20 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	int		i;
	size_t	n;
	size_t	h;

	i = 0;
	n = ft_strlen(needle);
	h = ft_strlen(hstack);
	while (hstack[i] != '\0' && i <= (int)(len - n))
	{
		if (hstack[i] == *needle && ft_strncmp(&hstack[i], needle, n) == 0)
			return (((char *)hstack + i));
		else if (n == 0)
			return ((char *)hstack);
		i++;
	}
	if (n == 0 && h == 0)
		return (((char *)hstack));
	else
		return ((void *)0);
}
