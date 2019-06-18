/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2019/06/14 21:29:50 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetr_del(t_map *brd, int row, int w, t_figure *figure)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - figure->y)
	{
		j = 0;
		while (j < 4 - figure->x)
		{
			if (figure->tetr[figure->y + i][figure->x + j] == '#')
				(brd->map)[row + i][w + j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		tetr_add(t_map *brd, int row, int w, t_figure *figure)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - figure->y)
	{
		j = 0;
		while (j < 4 - figure->x)
		{
			if (figure->tetr[figure->y + i][figure->x + j] == '#')
				(brd->map)[row + i][w + j] = figure->alpha;
			j++;
		}
		i++;
	}
	return (1);
}

int		is_fits(t_map *brd, t_figure *figure, int row, int w)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - figure->y)
	{
		j = 0;
		while (j < 4 - figure->x)
		{
			if (figure->tetr[figure->y + i][figure->x + j] == '#')
			{
				if (w + j >= brd->size_map || row + i >= brd->size_map
					|| (brd->map)[row + i][w + j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		tetr_next(t_map *brd, t_list *figures)
{
	int h;
	int w;

	if (!figures)
		return (1);
	h = 0;
	while (h < brd->size_map)
	{
		w = 0;
		while (w < brd->size_map)
		{
			if (is_fits(brd, figures->content, h, w))
			{
				tetr_add(brd, h, w, figures->content);
				if (tetr_next(brd, figures->next))
					return (1);
				else
					tetr_del(brd, h, w, figures->content);
			}
			w++;
		}
		h++;
	}
	return (0);
}

short	solve(t_map *brd, t_list *figures)
{
	while (!tetr_next(brd, figures))
		(brd->size_map)++;
	return (1);
}
