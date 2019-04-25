/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:03:44 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/01/04 16:04:19 by asimonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*f;
	int		tempo;

	tempo = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		f = read_basic(fd, tempo);
		if (!f)
		{
			return (err_exit());
		}
		print_board(begin_solve(f));
		close(fd);
	}
	else
	{
		write(1, "usage : fillit [file w/ pieces]\n", 32);
	}
	return (0);
}
