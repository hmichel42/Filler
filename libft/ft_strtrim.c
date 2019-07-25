/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:44:18 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 13:46:44 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup((char *)s)))
		return (NULL);
	while ((*str == ' ') || (*str == '\t') || (*str == '\n'))
		str++;
	i = ft_strlen(str) - 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i--;
	i++;
	str[i] = '\0';
	return (ft_strdup(str));
}
