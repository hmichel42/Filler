/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 14:16:28 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 02:42:31 by hmichel     ###    #+. /#+    ###.fr     */
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
	char		player;
	int			**heat;
	int			sqrt;
	int			**map;
	int			map_x;
	int			map_y;
	int			piece_x;
	int			piece_y;
	int			**piece;
	char		*gnl;
}				t_map;

typedef	struct	s_point
{
	int			pos_x;
	int			pos_y;
	int			score;
}				t_point;

int				get_next_line(const int fd, char **line);
/*
**	parsing.c
*/
void			ft_initstruc(t_map *map);
int				ft_player(t_map *map);
int				ft_mapsize(t_map *map);
int				ft_takemap(t_map *map, int fd);
int				ft_piecesize(t_map *map, int fd);
int				ft_takepiece(t_map *map, int fd);
int				ft_parsing(t_map *map, int fd);
/*
**	heat_map.c
*/
int				ft_heat_map(t_map *map);
/*
**	resolve.c
*/
t_point		ft_resolve(t_map map, int fd);

#endif
