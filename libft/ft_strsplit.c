/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2018/11/20 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	c_blocks(const char *s, char c)
{
	int	i;
	int	flag;
	int	result;

	i = 0;
	flag = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (flag == 0 && s[i] != c)
		{
			result += 1;
			flag = 1;
		}
		else if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	if (c == '\0' && ft_strlen(s) > 0)
		return (1);
	else
		return (result);
}

static char	*get_next_word(char **cursor, char c)
{
	char	*s_flag;
	char	*result;
	int		len;

	len = 0;
	result = NULL;
	while (**cursor == c && **cursor != '\0')
		(*cursor)++;
	s_flag = *cursor;
	while (**cursor != c && **cursor != '\0')
	{
		(*cursor)++;
		len++;
	}
	if (len > 0)
		if ((result = ft_memalloc(len + 1)))
			return (ft_strncpy(result, s_flag, len));
		else
			return (NULL);
	else
		return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*cursor;
	char	**w_array;
	int		i;
	int		w_q;

	if (s != NULL)
	{
		w_q = c_blocks(s, c);
		i = 0;
		cursor = (char *)s;
		if ((w_array = ft_memalloc((w_q + 1) * sizeof(*w_array))))
		{
			while ((w_array[i] = get_next_word(&cursor, c)))
				i++;
			w_array[i] = NULL;
			if (i < (w_q - 1))
				ft_arraydel((size_t)i, (void ***)(&w_array));
			return (w_array);
		}
	}
	return (NULL);
}
