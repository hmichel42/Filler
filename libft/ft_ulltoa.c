/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulltoa.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 17:09:44 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 17:02:23 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

static int		len(unsigned long long n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	if (len > 21)
		len = 21;
	return (len);
}

char			*ft_ulltoa(unsigned long long n)
{
	int		i;
	char	*str;

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
