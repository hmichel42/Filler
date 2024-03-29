/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/07 10:05:41 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 01:52:19 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	if (str == NULL)
		return (NULL);
	if (to_find[0] == '\0')
		return ((void *)str);
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			tmp = i;
			j = 1;
			if (to_find[1] == '\0')
				return ((void *)&str[i]);
			while (str[tmp + 1] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return ((void *)&str[i]);
				j++;
				tmp++;
			}
		}
	}
	return (0);
}
