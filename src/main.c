/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 16:30:42 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 17:22:16 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int		main(void)
{
	t_map		*map;
	t_piece		*piece;

	map = NULL;
	piece = NULL;
	if (!(ft_initstruc(&map, &piece)) || !ft_player(&map))
		return (1);	//sortie erreur
	if (!(ft_mapsize(&map)))
		return (1);	//sortie erreur
	
	//boucle infinie

	//Parsing
	if (!(ft_takemap(&map)))
		return (0);
	if (!(ft_piecesize(&piece)))
		return (0);
	if (!(ft_takepiece(&piece)))
		return (0);
	dprintf(1, "map->player = |%d|\n", map->player);
	//Resolution
	
	//fin boucle
	
	return (0);
}