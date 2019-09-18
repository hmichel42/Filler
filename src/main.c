/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 16:30:42 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 08:57:21 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_debug(int fd, t_map map)
{
	int		j;
	int		i;

	j = 0;
	dprintf(fd, "map->player = |%c|\n", map.player);
	dprintf(fd, "map->map_x = |%d|\n", map.map_x);
	dprintf(fd, "map->map_y = |%d|\n", map.map_y);
	while (j < map.map_y && map.map)
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
	dprintf(fd, "map->piece_x = |%d|\n", map.piece_x);
	dprintf(fd, "map->piece_y = |%d|\n", map.piece_y);
	j = 0;
	while (j < map.piece_y && map.piece)
	{
		i = 0;
		while (i < map.piece_x)
		{
			dprintf(fd, " %d", map.piece[j][i]);
			i++;
		}
		dprintf(fd, "\n");
		j++;
	}
	j = 0;
	while (j < map.map_y && map.heat)
	{
		i = 0;
		while (i < map.map_x)
		{
			dprintf(fd, " |%d|", map.heat[j][i]);
			i++;
		}
		dprintf(fd, "\n");
		j++;
	}
	dprintf(fd, "\n\n");
}

int		main(void)
{
	t_map		map;
	int			fd;

	fd = open("/Users/hmichel/Documents/Filler/trace.txt", O_WRONLY | O_APPEND);
	dprintf(fd, "\n\nDEBUT\n\n");
	write(1, "\nOUI\n", 5);
	ft_initstruc(&map);
	if (!ft_player(&map))
		return (1);	//sortie erreur
	if (!(ft_mapsize(&map)))
		return (1);	//sortie erreur
	ft_debug(fd, map);
	while (101 > 42)
	{
		get_next_line(0, &map.gnl);
		dprintf(fd, "gnl = %s\n", map.gnl);
		if (!ft_parsing(&map, fd))
			return (1);
		ft_debug(fd, map);
		if (map.map)
			if (!(ft_heat_map(&map)))
				return (1);
		ft_debug(fd, map);
	}
	return (0);
}