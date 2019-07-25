/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uhtoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 15:05:26 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 17:02:40 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		len(long long n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_uhtoa(long long n)
{
	int		i;
	char	*str;

	if (n < 0)
		n = 65536 - n;
	i = len(n);
	if (!(str = malloc((sizeof(char) * i))))
		return (0);
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
