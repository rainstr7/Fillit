/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessories.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:30:28 by ihahn             #+#    #+#             */
/*   Updated: 2019/06/14 21:14:04 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clear_struct(t_symbol *sym)
{
	sym->d = 0;
	sym->sh = 0;
	sym->nl = 0;
}

void		initialization_struct(t_figure *figure, short num)
{
	char	*alpha;
	short	i;

	i = 0;
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	figure->alpha = alpha[num];
	figure->y = 4;
	figure->x = 4;
}
