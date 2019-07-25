/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:50:02 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 10:32:05 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if (alst != NULL && del != NULL)
	{
		while (tmp && alst)
		{
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = tmp->next;
		}
	}
	*alst = NULL;
}
