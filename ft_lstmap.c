/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:35:14 by pholster       #+#    #+#                */
/*   Updated: 2019/02/06 03:34:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstmemdel);
	return (NULL);
}

static t_list	*list_set(t_list *elem)
{
	t_list *new;

	new = ft_lstnew(elem->content, elem->content_size);
	if (new == NULL)
		return (NULL);
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*returnlst;
	t_list	*prvlst;
	t_list	*newlst;

	if (lst == NULL || f == NULL)
		return (NULL);
	returnlst = list_set(f(lst));
	if (returnlst == NULL)
		return (NULL);
	lst = lst->next;
	prvlst = returnlst;
	while (lst != NULL)
	{
		newlst = list_set(f(lst));
		if (newlst == NULL)
			return (freeret(&returnlst));
		ft_lstaddbck(&prvlst, newlst);
		prvlst = newlst;
		lst = lst->next;
	}
	return (returnlst);
}
