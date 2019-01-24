/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:35:14 by pholster       #+#    #+#                */
/*   Updated: 2019/01/23 14:07:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			return (NULL);
		ft_lstaddbck(&prvlst, newlst);
		prvlst = newlst;
		lst = lst->next;
	}
	return (returnlst);
}
