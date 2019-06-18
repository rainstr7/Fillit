/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2018/11/20 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	size_t	len;

	i = 0;
	start = -1;
	len = 0;
	if (s != (void *)0)
	{
		while (s[i] != 0)
		{
			if (start < 0 && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				start = i;
			else if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				len = i - (start - 1);
			i++;
		}
	}
	if (s == (void *)0)
		return (NULL);
	else if (start == -1)
		return (ft_strdup(""));
	else
		return (ft_strsub(s, start, len));
}
