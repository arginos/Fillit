/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:01:33 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/01/04 16:02:13 by asimonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			err_exit(void)
{
	write(1, "error\n", 6);
	return (1);
}

int			check_validity(char *buf)
{
	int squares_sofar;
	int iter;

	iter = 0;
	squares_sofar = 0;
	while (iter < 20)
	{
		if (iter % 5 < 4)
		{
			if (!(buf[iter] == '.' || buf[iter] == '#'))
				return (-1);
			if (buf[iter] == '#')
			{
				squares_sofar++;
				if (squares_sofar > 4)
					return (-1);
			}
		}
		else if (buf[iter] != '\n')
			return (-1);
		iter++;
	}
	return (0);
}

int			inv_check(char *buf)
{
	int f;
	int connect_count;

	connect_count = 0;
	f = 0;
	while (f < 21)
	{
		if (buf[f] == '#')
		{
			if ((f + 5) < 20 && buf[f + 5] == '#')
				connect_count++;
			if ((f - 5) >= 0 && buf[f - 5] == '#')
				connect_count++;
			if ((f + 1) < 20 && buf[f + 1] == '#')
				connect_count++;
			if ((f - 1) >= 0 && buf[f - 1] == '#')
				connect_count++;
		}
		f++;
	}
	if (connect_count == 6 || connect_count == 8)
		return (1);
	return (-1);
}
