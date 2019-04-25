/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:02:31 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/01/04 16:03:10 by asimonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_mino
{
	char	letter_iter;
	char	**contents;
	int		x;
	int		y;
}				t_mino;

typedef struct	s_map
{
	char	**content;
	int		area;
}				t_map;

void			maxmin_get(t_coord *max, t_coord *min, char *buf);
void			ft_lstrev(t_list **alst);
t_coord			*new_coord(int x, int y);
t_mino			*new_tetrimino(char **contents, int x, int y, char letter_iter);
t_mino			*trim_mino(char *buf, char iter_val);
t_list			*read_basic(int fd, int wahu);
int				recur_solve(t_map *mapo, t_list *f);
t_map			*begin_solve(t_list *f);
int				err_exit(void);
int				check_validity(char *buf);
int				inv_check(char *buf);
void			print_board(t_map *map);
t_map			*blank_map(int size);
int				put_piece(t_mino *mino, t_map
						*map, t_coord *coord, char chariter);
int				place_piece(t_mino *mino, t_map *map, int x_trg, int y_trg);
#endif
