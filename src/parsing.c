/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 14:03:14 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 15:27:32 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_initstruc(t_map *map, t_piece *piece)
{
	map->map_x = 0;
	map->map_y = 0;
	map->round = 0;
	piece->piece_x = 0;
	piece->piece_y = 0;
}

int		ft_player(t_map *map, int fd)
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
	dprintf(fd, "player OK\n");
	return (1);
}

int		ft_mapsize(t_map *map, int fd)
{
	int		i;
	//int		j;
	char	*str;
	//char	temp;
	str = NULL;
	if (get_next_line(0, &str) == -1)
		return (0);
	while (str[0] != 'P' && str[1] != 'l')
	{	
		ft_strdel(&str);
		if (get_next_line(0, &str) == -1)
			return (0);
	}
	while (str && !ft_isdigit((int)*str)) //str += 8;
		str++;
	//dprintf(fd, "EN EFFET |%s|\n", str);
	i = -1;
	while (str[++i] != ' ')
		map->map_y = map->map_y * 10 + (int)str[i] - 48;
	while (str[++i] != ':')
		map->map_x = map->map_x * 10 + (int)str[i] - 48;
	dprintf(fd, "mapsize OK\n");
	return (1);
}

int		ft_piecesize(t_piece *piece, int fd, char *str)
{
	int		i;
	int		j;
	char	temp[10];

	dprintf(fd, "piecesize debut |%s|\n", str);
	while (str[0] != 'P' && str[1] != 'i')
	{	
		ft_strdel(&str);
		if (get_next_line(0, &str) == -1)
			return (0);
	}
	while (str && !ft_isdigit((int)*str))
		str++;
	i = -1;
	while (str[++i] != ' ')
		temp[i] = str[i];
	temp[i] = '\0';
	piece->piece_x = ft_atoi(temp);
	//dprintf(fd, "CA MARCHE\n");
	j = i + 1;
	while (str[++i] != ':')
		temp[i - j] = str[i];
	temp[i - j] = '\0';
	piece->piece_y = ft_atoi(temp);
	return (1);
}

int		ft_takepiece(t_piece *piece, int fd)
{
	char	*str;
	int		i;
	int		j;

	dprintf(fd, "DEBUT takepiece\n");
	if (!(get_next_line(0, &str) == -1))
		return (0);
	dprintf(fd, "takesize ligne |%s|\n", str);
	if (!(piece->piece = (int **)malloc(sizeof(int *) * (piece->piece_y))))
		return (0);
	j = -1;
	while (++j < piece->piece_y)
	{
		i = -1;
		if (!(piece->piece[j] = (int *)malloc(sizeof(int) * (piece->piece_x))))
			return (0);
		dprintf(fd, "takesize ligne |%s|\n", str);
		while (++i < piece->piece_x)
		{
			if (str[i] == '.')
				piece->piece[j][i] = 0;
			if (str[i] == '*')
				piece->piece[j][i] = 1;
			dprintf(fd, "nouw int |%d|\n", piece->piece[j][i]);
		}
		ft_strdel(&str);
		if (!(get_next_line(0, &str) == -1))
			return (0);
		dprintf(fd, "nouvelle ligne |%s|\n", str);
	}
	return (1);
}

int		ft_takemap(t_map *map, t_piece *piece, int fd)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	dprintf(fd, "CA MARCHE\n");
	if (get_next_line(0, &str) == -1)
		return (0);
	while (str && *str != '0' && *(str + 1) != '0')
	{	
		ft_strdel(&str);
		if (get_next_line(0, &str) == -1)
			return (0);
	}
	dprintf(fd, "CA MARCHE\n");
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
			if (str[i + 4] == '.')
				map->map[j][i] = -1;
			else if (str[i + 4] == map->player || str[i + 4] == map->player - 32)
				map->map[j][i] = 0;
			else if (str[i + 4] != map->player && str[i + 4] != map->player - 32)
				map->map[j][i] = -2;
		}
		ft_strdel(&str);
		if (get_next_line(0, &str) == -1)
			return (0);
	}
	dprintf(fd, "CA MARCHEEEEEE\n");
	if (!(ft_piecesize(piece, fd, str)))
		return (0);
	if (!(ft_takepiece(piece, fd)))
		return (0);
	return (1);
}



//free map et free piece a faire en 2version (avec et sans free de la struct pour conserver les tailles x * y)
//initstruct, ft_player et mapsize a mettre avant boucle infinie
/*
int		ft_parsing(t_map *map, t_piece *piece)
{
	if (!(ft_takemap(&map)))
		return (0);
	if (!(ft_piecesize(&piece)))
		return (0);
	if (!(ft_takepiece(&piece)))
		return (0);
	return (1);
}*/