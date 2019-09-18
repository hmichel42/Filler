/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/18 02:04:18 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 08:57:06 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	ft_init_value(t_map *map)
{
	int		i;
	int		j;

	j = -1;
	while (++j < map->map_y)
	{
		i = -1;
		while (++i < map->map_x)
		{
			if (j - 1 >= 0 && map->heat[j][i] == -1 && map->heat[j - 1][i] == 0)
				map->heat[j - 1][i] = 1;
			if (j + 1 < map->map_y && map->heat[j][i] == -1 && map->heat[j + 1][i] == 0)
				map->heat[j + 1][i] = 1;
			if (i - 1 >= 0 && map->heat[j][i] == -1 && map->heat[j][i - 1] == 0)
				map->heat[j][i - 1] = 1;
			if (i + 1 < map->map_x && map->heat[j][i] == -1 && map->heat[j][i + 1] == 0)
				map->heat[j][i + 1] = 1;
		}
	}
	map->sqrt = (int)ft_sqrt_double(map->map_x * map->map_x + map->map_y * map->map_y, 0.1) + 1;
}

static int	ft_init_heatmap(t_map *map)
{
	int		i;
	int		j;

	j = -1;
	if (!(map->heat = (int **)malloc(sizeof(int *) * (map->map_y))))
		return (0);
	while (++j < map->map_y)
	{
		i = -1;
		if (!(map->heat[j] = (int *)malloc(sizeof(int) * (map->map_x))))
			return (0);
		while (++i < map->map_x)
			map->heat[j][i] = map->map[j][i];
	}
	ft_init_value(map);
	return (1);
}

int			ft_heat_map(t_map *map)
{
	int		i;
	int		j;
	int		k;

	if (!(ft_init_heatmap(map)))
		return (0);
	k = 2;
	while (k < map->sqrt)
	{
		j = -1;
		while (++j < map->map_y)
		{
			i = -1;
			while (++i < map->map_x)
			{
				if (j - 1 >= 0 && map->heat[j][i] == k - 1 && map->heat[j - 1][i] == 0)
					map->heat[j - 1][i] = k;
				if (j + 1 < map->map_y && map->heat[j][i] == k - 1 && map->heat[j + 1][i] == 0)
					map->heat[j + 1][i] = k;
				if (i - 1 >= 0 && map->heat[j][i] == k - 1 && map->heat[j][i - 1] == 0)
					map->heat[j][i - 1] = k;
				if (i + 1 < map->map_x && map->heat[j][i] == k - 1 && map->heat[j][i + 1] == 0)
					map->heat[j][i + 1] = k;
			}
		}
		k++;
	}
	return (1);
}