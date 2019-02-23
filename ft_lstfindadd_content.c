/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfindadd_content.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 20:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 20:16:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfindadd_content(t_list *lst, void *content)
{
	t_list	*newlst;

	while (lst != NULL)
	{
		if (ft_memcmp(lst->content, content) == 0)
			return (lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	newlst = ft_lstnew(NULL, 0);
	if (newlst == NULL)
		return (NULL);
	newlst->content = content;
	if (lst != NULL)
		lst->next = newlst;
	return (newlst);
}
