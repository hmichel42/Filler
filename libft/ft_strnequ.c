/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 15:02:08 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 19:38:34 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		if ((ft_strncmp(s1, s2, n)) > 0 || (ft_strncmp(s1, s2, n) < 0))
			return (0);
		if ((ft_strncmp(s1, s2, n)) == 0)
			return (1);
	}
	return (0);
}
