/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 14:16:28 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 18:20:07 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define BUFF_SIZE 10

typedef struct	s_map
{
	int			round;
	char		player;
	int			**map;
	int			map_x;
	int			map_y;
}				t_map;
typedef	struct	s_piece
{
	int			piece_x;
	int			piece_y;
	int			**piece;
}				t_piece;
int				get_next_line(const int fd, char **line);
/*
**	parsing.c
*/
void			ft_initstruc(t_map *map, t_piece *piece);
int				ft_player(t_map *map, int fd);
int				ft_mapsize(t_map *map, int fd);
int				ft_takemap(t_map *map, t_piece *piece, int fd);
int				ft_piecesize(t_piece *piece, int fd, char *str);
int				ft_takepiece(t_piece *piece, int fd);
int				ft_parsing(t_map *map, t_piece *piece);

#endif
