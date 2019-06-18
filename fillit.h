/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:26:03 by ihahn             #+#    #+#             */
/*   Updated: 2019/06/14 21:28:26 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_figure
{
	short			x;
	short			y;
	char			tetr[4][4];
	char			alpha;
}					t_figure;

typedef struct		s_symbol
{
	short			d;
	short			sh;
	short			nl;
}					t_symbol;

typedef struct		s_map
{
	char			map[28][28];
	short			size_map;
}					t_map;

void				clear_struct(t_symbol *sym);
void				initialization_struct(t_figure *figure, short num);
void				ft_print_error();
void				ft_print_usage();
void				print_map(char board[28][28], short size);
short				solve(t_map *map, t_list *figures);
t_list				*check_and_build_list(char *filename, char *buff);

#endif
