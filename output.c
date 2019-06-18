/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:56:24 by ihahn             #+#    #+#             */
/*   Updated: 2019/06/14 20:58:56 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_print_usage(void)
{
	ft_putstr("Need one file with tetriminos as argument\n");
	exit(0);
}

void	print_map(char board[28][28], short size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(board[row][col] ? board[row][col] : '.');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
