/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 16:30:42 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 15:18:59 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_debug(int fd, t_piece piece, t_map map)
{
	int		j;
	int		i;

	j = 0;
	dprintf(fd, "map->player = |%c|\n", map.player);
	dprintf(fd, "map->map_x = |%d|\n", map.map_x);
	dprintf(fd, "map->map_y = |%d|\n", map.map_y);
	dprintf(fd, "map->round = |%d|\n", map.round);
	while (j < map.map_y)
	{
		i = 0;
		while (i < map.map_x)
		{
			dprintf(fd, " %d", map.map[j][i]);
			i++;
		}
		dprintf(fd, "\n");
		j++;
	}
	dprintf(fd, "piece->piece_x = |%d|\n", piece.piece_x);
	dprintf(fd, "piece->piece_y = |%d|\n", piece.piece_y);
	j = 0;
	/*while (j < piece.piece_y)
	{
		i = 0;
		while (i < piece.piece_x)
		{
			dprintf(fd, " %d", piece.piece[j][i]);
			i++;
		}
		dprintf(fd, "\n");
		j++;
	}*/
	dprintf(fd, "\n\n");
}

int		main(void)
{
	t_map		map;
	t_piece		piece;
	int			fd;

	fd = open("/Users/hmichel/Documents/resources_Filler/text.log", O_WRONLY | O_APPEND);
	dprintf(fd, "\n\nDEBUT\n");
	ft_initstruc(&map, &piece);
	if (!ft_player(&map, fd))
		return (1);	//sortie erreur
	ft_debug(fd, piece, map);
	if (!(ft_mapsize(&map, fd)))
		return (1);	//sortie erreur
	while (101 > 42)
	{
		if (!(ft_takemap(&map, &piece, fd))) //pb de return 0
			return (0);
		ft_debug(fd, piece, map);
	}
	return (0);
}