/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 07:34:41 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:06:49 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)str);
	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j + i] == to_find[i] && j + i < len)
		{
			if (!to_find[++i])
				return ((char *)(str + j));
		}
		j++;
	}
	return (0);
}
