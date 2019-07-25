/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 20:58:53 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 15:38:24 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_affichage(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void			ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_affichage();
	if (nb >= 10 && nb <= 2147483647)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10 && nb > -10)
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		ft_putchar(nb % 10 + '0');
	}
	if (nb <= -10 && nb >= -2147483647)
	{
		nb = -nb;
		ft_putchar('-');
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
