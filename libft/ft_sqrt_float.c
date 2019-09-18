/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt_float.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/18 08:29:02 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 08:39:34 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt_double(int nb, double preci)
{
	double	i;

	i = 0.0;
	if (nb <= 0)
		return (0.0);
	while (i * i <= nb)
		i += preci;
	return (i);
}