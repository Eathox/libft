/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfindadd_size.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 20:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstfindadd_size(t_list *lst, size_t size)
{
	t_list	*newlst;

	while (lst != NULL)
	{
		if (lst->content_size == size)
			return (lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	newlst = ft_lstnew(NULL, 0);
	if (newlst == NULL)
		return (NULL);
	newlst->content_size = size;
	if (lst != NULL)
		lst->next = newlst;
	return (newlst);
}
