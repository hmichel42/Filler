/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:23:37 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:12:59 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char u1;
	unsigned char u2;

	while (n--)
	{
		u1 = *(const unsigned char *)s1;
		u2 = *(const unsigned char *)s2;
		if (u1 != u2)
			return ((int)u1 - (int)u2);
		s1++;
		s2++;
	}
	return (0);
}
