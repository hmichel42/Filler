/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:03:09 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 10:10:28 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*elem;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (!(res = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	tmp = res;
	while (lst)
	{
		elem = f(lst);
		if (!(res->next = ft_lstnew(elem->content, elem->content_size)))
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (tmp);
}
