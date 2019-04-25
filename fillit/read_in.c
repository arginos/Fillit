/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:05:00 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/01/04 16:05:43 by asimonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_mino		*trim_mino(char *buf, char iter_val)
{
	t_coord		*max;
	t_coord		*min;
	char		**tetr_content;
	t_mino		*tetr_reter;
	int			f;

	f = 0;
	max = new_coord(0, 0);
	min = new_coord(3, 3);
	maxmin_get(max, min, buf);
	tetr_content = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	while (f < max->y - min->y + 1)
	{
		tetr_content[f] = ft_strnew(max->x - min->x + 2);
		ft_strncpy(tetr_content[f], buf + (min->x)
			+ (f + min->y) * 5, max->x - min->x + 1);
		f++;
	}
	tetr_reter = new_tetrimino(tetr_content,
	max->x - min->x + 1, max->y - min->y + 1, iter_val);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetr_reter);
}

t_list		*read_basic(int fd, int wahu)
{
	char	*buf;
	char	iter;
	t_mino	*current;
	int		rd_size;
	t_list	*lst;

	lst = 0;
	iter = 'A' - 1;
	buf = ft_strnew(21);
	while ((rd_size = read(fd, buf, 21)) >= 20)
	{
		if (check_validity(buf) < 0 || inv_check(buf) < 0)
			return (0);
		if (!(current = trim_mino(buf, ++iter)))
			return (0);
		if (buf[20] == '\n')
			rd_size = -999;
		ft_lstadd(&lst, ft_lstnew(current, sizeof(t_mino)));
		ft_bzero(buf, 21);
		wahu = rd_size;
	}
	if (rd_size || (wahu == -999 && iter > 'A'))
		return (0);
	ft_lstrev(&lst);
	return (lst);
}

int			recur_solve(t_map *mapo, t_list *f)
{
	int		x;
	int		y;
	t_mino	*trmino;

	if (!f)
		return (1);
	y = -1;
	trmino = (t_mino *)(f->content);
	while (++y < mapo->area - trmino->y + 1)
	{
		x = -1;
		while (++x < mapo->area - trmino->x + 1)
		{
			if (place_piece(trmino, mapo, x, y))
			{
				if (recur_solve(mapo, f->next))
					return (1);
				else
					put_piece(trmino, mapo, new_coord(x, y), '.');
			}
		}
	}
	return (0);
}

t_map		*begin_solve(t_list *f)
{
	t_map	*map;
	int		s;

	s = ft_sqrt(ft_lstlen(f) * 4);
	map = blank_map(s);
	while (!recur_solve(map, f))
	{
		map = blank_map(map->area + 1);
	}
	return (map);
}
