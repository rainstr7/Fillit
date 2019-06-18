/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:24:52 by ihahn             #+#    #+#             */
/*   Updated: 2019/06/14 21:11:52 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_del(void *content, size_t size)
{
	ft_memset(content, 0, size);
	ft_memdel(&content);
}

static void		clear_map(char map[28][28])
{
	short	i;
	short	j;

	i = 0;
	j = 0;
	while (i < 28)
	{
		while (j < 28)
		{
			map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

static short	ft_sqrt(short num)
{
	int			i;
	int			result;

	result = 0;
	i = 0;
	while (result < num)
	{
		i++;
		result = i * i;
	}
	return (i);
}

static short	get_size_list(t_list *begin_list)
{
	int			size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

int				main(int argc, char **argv)
{
	t_map		board;
	t_list		*figures;
	char		buff[20];

	if (argc != 2)
		ft_print_usage();
	clear_map(board.map);
	figures = check_and_build_list(argv[1], buff);
	board.size_map = ft_sqrt(get_size_list(figures) * 4);
	if (!solve(&board, figures))
		ft_print_error();
	ft_lstdel(&figures, &ft_del);
	print_map(board.map, board.size_map);
	return (0);
}
