/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 14:03:14 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 17:25:28 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_initstruc(t_map **map, t_piece **piece) //initialiser var a NULL lors de declaration avant appel fonction
{
	if (*map && *piece)
		return (1);
	if (!(*map = (t_map *)malloc(sizeof(t_map *))))
		return (0);
	(*map)->map_x = 0;
	(*map)->map_y = 0;
	(*map)->round = 0;
	if (!(*piece = (t_piece *)malloc(sizeof(t_piece *))))
		return (0);
	(*piece)->piece_x = 0;
	(*piece)->piece_y = 0;
	return (1);
}

int		ft_player(t_map **map)
{
	char *str;

	(*map)->player = 0;
	if (get_next_line(0, &str) == -1)
		return (0);
	while (str[0] != '$')
	{	
		free(str);
		if (get_next_line(0, &str) <= 0)
			return (0);
	}
	while (str)
	{
		if (str + 1  && str + 2  && str + 3  && str + 4  && str + 5
		&& str + 6 && *str == 'h' && *(str + 1) == 'm' && *(str + 2) == 'i' &&
		*(str + 3) == 'c' && *(str + 4) == 'h' && *(str + 5) == 'e' && *(str + 6) == 'l')
			(*map)->player = 1;
		str++;
	}
	if ((*map)->player == 0)
		(*map)->player = 2;
	free(str);
	return (1);
}

int		ft_mapsize(t_map **map)
{
	int		i;
	int		j;
	char	*str;
	char	temp[10];

	str = NULL;
	if (get_next_line(0, &str) == 1)
		return (0);
	while (*str != 'P' && *(str + 1) != 'l')
	{	
		free(str);
		if (get_next_line(0, &str) <= 0)
			return (0);
	}
	while (str && !ft_isdigit((int)*str)) //str += 8;
		str++;
	i = 7;
	while (str[++i] != ' ')
		temp[i - 8] = str[i];
	temp[i - 8] = '\0';
	(*map)->map_y = ft_atoi(temp);
	i += 1;
	j = i + 1;
	while (str[++i] != ':')
		temp[i - j] = str[i];
	temp[i - j] = '\0';
	(*map)->map_x = ft_atoi(temp);
	return (1);
}

int		ft_takemap(t_map **map)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	if (get_next_line(0, &str) == -1)
		return (0);
	while (*str != '0' && *(str + 1) != '0')
	{	
		free(str);
		if (get_next_line(0, &str) <= 0)
			return (0);
	}
	j = -1;
	if (!((*map)->map = (int **)malloc(sizeof(int *) * ((*map)->map_y))))
		return (0);
	while (++j < (*map)->map_y)
	{
		i = 3;
		if (!((*map)->map[j] = (int *)malloc(sizeof(int) * ((*map)->map_x + 1))))
			return (0);
		while (++i < (*map)->map_x + 4)
		{
			if (str[i] == '.')
				(*map)->map[j][i - 4] = -2;
			if (str[i] == 'O' || str[i] == 'o')
				(*map)->map[j][i - 4] = 0;
			if (str[i] == 'x' || str[i] == 'X')
				(*map)->map[j][i - 4] = -1;
		}
		free(str);
		if (!(get_next_line(0, &str) == -1))
			return (0);
	}
	return (1);
}

int		ft_piecesize(t_piece **piece)
{
	int		i;
	int		j;
	char	*str;
	char	temp[10];

	str = NULL;
	if (get_next_line(0, &str) == -1)
		return (0);
	while (*str != 'P' && *(str + 1) != 'i') //peut-etre inutile apres 1er call
	{	
		free(str);
		if (get_next_line(0, &str) <= 0)
			return (0);
	}
	while (str && !ft_isdigit((int)*str)) //str += 6;
		str++;
	i = 5;
	while (str[++i] != ' ')
		temp[i - 6] = str[i];
	temp[i - 6] = '\0';
	(*piece)->piece_y = ft_atoi(temp);
	i += 1;
	j = i + 1;
	while (str[++i] != ':')
		temp[i - j] = str[i];
	temp[i - j] = '\0';
	(*piece)->piece_x = ft_atoi(temp);
	return (1);
}

int		ft_takepiece(t_piece **piece)
{
	char	*str;
	int		i;
	int		j;

	if (get_next_line(0, &str) == -1)
		return (0);
	if (!((*piece)->piece = (int **)malloc(sizeof(int *) * ((*piece)->piece_y))))
		return (0);
	j = -1;
	while (++j < (*piece)->piece_y)
	{
		i = -1;
		if (!((*piece)->piece[j] = (int *)malloc(sizeof(int) * ((*piece)->piece_x + 1))))
			return (0);
		while (++i < (*piece)->piece_x)
		{
			if (str[i] == '.')
				(*piece)->piece[j][i] = 0;
			if (str[i] == '*')
				(*piece)->piece[j][i] = 1;
		}
		free(str);
		if (!(get_next_line(0, &str) == -1))
			return (0);
	}
	return (1);
}

//free map et free piece a faire en 2version (avec et sans free de la struct pour conserver les tailles x * y)
//initstruct, ft_player et mapsize a mettre avant boucle infinie

int		ft_parsing(t_map *map, t_piece *piece)
{
	if (!(ft_takemap(&map)))
		return (0);
	if (!(ft_piecesize(&piece)))
		return (0);
	if (!(ft_takepiece(&piece)))
		return (0);
	return (1);
}