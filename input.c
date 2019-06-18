/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:25:05 by ihahn             #+#    #+#             */
/*   Updated: 2019/06/14 21:33:44 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_list	*lstnew_ins(void *content)
{
	t_list		*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = content;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}

static t_list	*write_list(t_list *newlist, t_list **lst, t_figure *figure)
{
	if (!newlist)
	{
		newlist = lstnew_ins(figure);
		*lst = newlist;
	}
	else
	{
		newlist->next = lstnew_ins(figure);
		newlist = newlist->next;
	}
	return (newlist);
}

static short	check_shape(const char *buff, int i, t_figure *figure)
{
	short		sharp;

	sharp = 0;
	if (i % 5 > 0 && buff[i - 1] == '#')
		sharp++;
	if (i % 5 < 4 && buff[i + 1] == '#')
		sharp++;
	if (i / 5 > 0 && buff[i - 5] == '#')
		sharp++;
	if (i / 5 < 4 && buff[i + 5] == '#')
		sharp++;
	if (i % 5 < figure->x)
		figure->x = i % 5;
	if (i / 5 < figure->y)
		figure->y = i / 5;
	return (sharp);
}

static t_figure	*check_and_build_shape(char *buff, short num)
{
	t_figure	*figure;
	t_symbol	sym;
	short		i;

	i = 0;
	figure = (t_figure *)ft_memalloc(sizeof(t_figure));
	clear_struct(&sym);
	initialization_struct(figure, num);
	while (i < 20)
	{
		if (buff[i] == '\n')
			i % 5 == 4 ? sym.nl += 1 : ft_print_error();
		else if (buff[i] == '.' || buff[i] == '#')
		{
			buff[i] == '.' ? (sym.d += 1) : \
				(sym.sh += check_shape(buff, i, figure));
			figure->tetr[i / 5][i % 5] = buff[i];
		}
		else
			ft_print_error();
		i++;
	}
	if ((sym.d != 12) || ((sym.sh != 6) && (sym.sh != 8)) || (sym.nl != 4))
		ft_print_error();
	return (figure);
}

t_list			*check_and_build_list(char *filename, char *buff)
{
	t_list		*lst;
	t_list		*newlist;
	t_figure	*figure;
	int			fd;
	short		num;

	num = 0;
	newlist = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		ft_print_error();
	while (1)
	{
		if (num > 25 || read(fd, buff, 20) != 20)
			ft_print_error();
		if (!(figure = check_and_build_shape(buff, num)))
			ft_print_error();
		if (!(newlist = write_list(newlist, &lst, figure)))
			ft_print_error();
		if (!(read(fd, buff, 1)))
			break ;
		num++;
	}
	close(fd);
	return (lst);
}
