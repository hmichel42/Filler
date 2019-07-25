/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 09:31:54 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 17:01:45 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const **s2)
{
	char	*str;

	if (!s1 || *s2 == NULL ||
	!(str = ft_strnew(ft_strlen(s1) + ft_strlen(*s2))))
		return (NULL);
	str = ft_strcpy(str, (char *)s1);
	str = ft_strcat(str, (char *)*s2);
	free(s2);
	return (str);
}
