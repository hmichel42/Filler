/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:56:34 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 17:40:14 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *s;
	char *d;

	s = (char *)src;
	d = (char *)dst;
	while (n-- > 0)
	{
		if ((*d++ = *s++) == (char)c)
			return (d);
	}
	return (NULL);
}
