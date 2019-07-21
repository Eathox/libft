/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:07:37 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_list	*freeret(t_list *lst)
{
	free(lst);
	return (NULL);
}

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content != NULL)
	{
		lst->content = ft_memdup(content, content_size);
		if (lst->content == NULL)
			return (freeret(lst));
		lst->content_size = content_size;
	}
	return (lst);
}
