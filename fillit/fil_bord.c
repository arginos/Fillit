/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_bord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:00:22 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/01/04 16:01:04 by asimonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_board(t_map *map)
{
	int iter;

	iter = 0;
	while (map->content[iter] != 0)
	{
		ft_putendl(map->content[iter]);
		iter++;
	}
}

t_map		*blank_map(int size)
{
	char	**f;
	int		a;
	int		b;
	t_map	*reter;

	a = 0;
	b = 0;
	reter = (t_map *)malloc(sizeof(t_map));
	f = (char **)ft_memalloc(sizeof(char *) * size + 1);
	while (a < size)
	{
		f[a] = ft_strnew(size + 1);
		b = 0;
		while (b < size)
		{
			f[a][b] = '.';
			b++;
		}
		a++;
	}
	reter->content = f;
	reter->area = size;
	return (reter);
}

int			put_piece(t_mino *mino, t_map *map, t_coord *coord, char chariter)
{
	int x;
	int y;

	x = 0;
	while (x < mino->x)
	{
		y = 0;
		while (y < mino->y)
		{
			if (mino->contents[y][x] == '#')
				map->content[coord->y + y][coord->x + x] = chariter;
			y++;
		}
		x++;
	}
	ft_memdel((void **)&coord);
	return (1);
}

int			place_piece(t_mino *mino, t_map *map, int x_trg, int y_trg)
{
	int x;
	int y;

	x = 0;
	while (x < mino->x)
	{
		y = 0;
		while (y < mino->y)
		{
			if ((y_trg + y >= map->area || x_trg + x >= map->area) ||
			(mino->contents[y][x] == '#'
			&& map->content[y_trg + y][x_trg + x] != '.'))
				return (0);
			y++;
		}
		x++;
	}
	put_piece(mino, map, new_coord(x_trg, y_trg), mino->letter_iter);
	return (1);
}
