/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 13:52:48 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 12:44:55 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char				*lilchain;
	unsigned int		i;

	i = 0;
	if (!(lilchain = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size + 1)
	{
		lilchain[i] = '\0';
		i++;
	}
	return (lilchain);
}
