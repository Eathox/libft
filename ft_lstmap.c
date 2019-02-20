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

t_list			*ft_lstmap(const t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*retlst;
	t_list	*prvlst;
	t_list	*newlst;

	if (lst == NULL || f == NULL)
		return (NULL);
	retlst = list_set(f(lst));
	if (retlst == NULL)
		return (NULL);
	current = current->next;
	prvlst = retlst;
	while (current != NULL)
	{
		newlst = list_set(f(current));
		if (newlst == NULL)
			return (freeret(&retlst));
		ft_lstaddbck(&prvlst, newlst);
		prvlst = newlst;
		current = current->next;
	}
	return (retlst);
}
