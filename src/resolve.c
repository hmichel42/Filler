/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/18 19:53:57 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 05:42:33 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_point	ft_init_point(void)
{
	t_point		point;

	point.pos_x = 0;
	point.pos_y = 0;
	point.score = 2147483647;
	return (point);
}

static int	ft_onlyone(int ip, int jp, t_map map)
{
	int		i;
	int		j;
	int		nb;

	j = -1;
	nb = 0;
	while (++j < map.piece_y && nb <= 1)
	{
		if (jp + j >= map.map_y)
			return (0);
		i = -1;
		while (++i < map.piece_x)
		{
			if (ip + i >= map.map_x)
				return (0);
			if (map.piece[j][i] == 1 && map.heat[jp + j][ip + i] == -2)
				nb++;
		}
	}
	if (nb == 1)
		return (1);
	return (0);
}

static int	ft_heat_value(int ip, int jp, t_map map)
{
	int		i;
	int		j;
	int		nb;

	j = -1;
	nb = 0;
	while (++j < map.piece_y && nb <= 1)
	{
		i = -1;
		if (jp + j >= map.map_y)
			return (-1);
		while (++i < map.piece_x)
		{
			if (ip + i >= map.map_x || map.heat[jp + j][ip + i] == -1)
				return (-1);
			if (map.piece[j][i] == 1 && map.heat[jp + j][ip + i] != -2)
				nb += map.heat[jp + j][ip + i];
		}		
	}
	return (nb);
}

static t_point	ft_best_pos(t_map map, int fd)
{
	int			i;
	int			j;
	t_point		point;

	point = ft_init_point();
	j = -1;
	while (++j < map.map_y)
	{
		i = -1;
		while (++i < map.map_x)
		{
			if (ft_onlyone(i, j, map))
			{
				dprintf(fd, "nouvelle case onlyone i = %d, j = %d\n", i, j);
				if (ft_heat_value(i, j, map) < point.score) //voir cas ou heat_value = point.score pour opti si le nouveau cas est meilleur que le score actuel
				{
					point.score = ft_heat_value(i, j, map);
					point.pos_x = i;
					point.pos_y = j;
					dprintf(fd, "nouvelle case heat i = %d, j = %d et score = %d\n", i, j, point.score);
				}
			}
		}
	}
	dprintf(fd, "return best_pos x = %d, y = %d\n", point.pos_x, point.pos_y);
	return (point);
}

t_point		ft_resolve(t_map map, int fd)
{
	t_point		point;

	point = ft_best_pos(map, fd);
	ft_putnbr_fd(point.pos_y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(point.pos_x, 1);
	ft_putchar_fd('\n', 1);
	dprintf(fd, "\nLa piece est posee\n");
	return (point);
}