/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strequ.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 19:27:45 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 19:37:52 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		if ((ft_strcmp(s1, s2)) > 0 || (ft_strcmp(s1, s2) < 0))
			return (0);
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	}
	return (0);
}
