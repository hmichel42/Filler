/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 14:03:14 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 03:29:52 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_initstruc(t_map *map)
{
	map->player = 'u';
	map->map_x = 0;
	map->map_y = 0;
	map->piece_x = 0;
	map->piece_y = 0;
	map->gnl = NULL;
}

int		ft_player(t_map *map)
{
	char *str;

	str = NULL;
	map->player = 0;
	if (get_next_line(0, &str) == -1)
		return (0);
	if (str && str[10] == '1')
		map->player = 'o';
	else
		map->player = 'x';
	ft_strdel(&str);
	return (1);
}

int		ft_mapsize(t_map *map)
{
	int		i;
	char	*str;

	str = NULL;
	if (get_next_line(0, &str) == -1)
		return (0);
	while (str[0] != 'P' && str[1] != 'l')
	{	
		ft_strdel(&str);
		if (get_next_line(0, &str) == -1)
			return (0);
	}
	while (str && !ft_isdigit((int)*str))
		str++;
	i = -1;
	while (str[++i] != ' ')
		map->map_y = map->map_y * 10 + (int)str[i] - 48;
	while (str[++i] != ':')
		map->map_x = map->map_x * 10 + (int)str[i] - 48;
	return (1);
}

int		ft_piecesize(t_map *map, int fd)
{
	int		k;

	dprintf(fd, "piecesize debut |%s|\n", map->gnl);
	k = 0;
	while (map->gnl[k] && !ft_isdigit((int)map->gnl[k]))
		k++;
	map->piece_y = ft_atoi(&(map->gnl[k]));
	while (map->gnl[k] && ft_isdigit((int)map->gnl[k]))
		k++;
	map->piece_x = ft_atoi(&(map->gnl[k]));
	return (1);
}

int		ft_takepiece(t_map *map, int fd)
{
	int		i;
	int		j;

	dprintf(fd, "DEBUT takepiece\n");
	dprintf(fd, "takesize ligne |%s|\n", map->gnl);
	if (!(map->piece = (int **)malloc(sizeof(int *) * (map->piece_y))))
		return (0);
	j = -1;
	while (++j < map->piece_y)
	{
		i = -1;
		if (!(map->piece[j] = (int *)malloc(sizeof(int) * (map->piece_x))))
			return (0);
		dprintf(fd, "takesize ligne |%s|\n", map->gnl);
		if (get_next_line(0, &map->gnl) == -1)
			return (0);
		while (++i < map->piece_x)
		{
			if (map->gnl[i] == '.')
				map->piece[j][i] = 0;
			if (map->gnl[i] == '*')
				map->piece[j][i] = 1;
		}
		ft_strdel(&map->gnl);
	}
	return (1);
}

int		ft_takemap(t_map *map, int fd)
{
	int		i;
	int		j;

	j = -1;
	if (!(map->map = (int **)malloc(sizeof(int *) * (map->map_y))))
		return (0);
	while (++j < map->map_y)
	{
		i = -1;
		if (!(map->map[j] = (int *)malloc(sizeof(int) * (map->map_x))))
			return (0);
		while (++i < map->map_x)
		{
			if (map->gnl[i + 4] == '.')
				map->map[j][i] = 0;
			else if (map->gnl[i + 4] == map->player || map->gnl[i + 4] == map->player - 32)
				map->map[j][i] = -2;
			else if (map->gnl[i + 4] != map->player && map->gnl[i + 4] != map->player - 32)
				map->map[j][i] = -1;
		}
		ft_strdel(&map->gnl);
		if (get_next_line(0, &map->gnl) == -1)
			return (0);
	}
	dprintf(fd, "takemap OK\n");
	return (1);
}

int		ft_parsing(t_map *map, int fd)
{
	if (ft_strstr(map->gnl, "000"))
		if (!(ft_takemap(map, fd)))
			return (0);
	if (ft_strstr(map->gnl, "Piece"))
	{
		if (!(ft_piecesize(map, fd)))
			return (0);
		if (!(ft_takepiece(map, fd)))
			return (0);
	}
	return (1);
}