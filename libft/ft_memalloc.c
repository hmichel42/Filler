/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 17:16:28 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 17:09:22 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *urmother;

	if (!(urmother = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(urmother, size + 1);
	return (urmother);
}
