/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:06:25 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/01/04 16:07:07 by asimonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		maxmin_get(t_coord *max, t_coord *min, char *buf)
{
	int f;

	f = 0;
	while (buf[f])
	{
		if (buf[f] == '#')
		{
			if (f / 5 > max->y)
				max->y = f / 5;
			if (f / 5 < min->y)
				min->y = f / 5;
			if (f % 5 > max->x)
				max->x = f % 5;
			if (f % 5 < min->x)
				min->x = f % 5;
		}
		f++;
	}
}

void		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

t_coord		*new_coord(int x, int y)
{
	t_coord		*reter;

	if (!(reter = ft_memalloc(sizeof(t_coord *))))
		return (0);
	reter->x = x;
	reter->y = y;
	return (reter);
}

t_mino		*new_tetrimino(char **contents, int x, int y, char letter_iter)
{
	t_mino		*reter;

	if (!(reter = ft_memalloc(sizeof(struct s_mino))))
		return (0);
	reter->letter_iter = letter_iter;
	reter->contents = contents;
	reter->x = x;
	reter->y = y;
	return (reter);
}
