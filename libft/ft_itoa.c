/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:46:21 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 05:32:53 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int				len(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int				neg(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int				one(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char					*ft_itoa(int n)
{
	int		i;
	int		tmp2;
	char	*str;

	if (n == -2147483648)
	{
		str = ft_memalloc(12);
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	tmp2 = one(n);
	n = neg(n);
	i = len(n);
	if (!(str = ft_memalloc(i + tmp2)))
		return (0);
	tmp2 == 1 ? str[0] = '-' : 0;
	while (i--)
	{
		str[i + tmp2] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
