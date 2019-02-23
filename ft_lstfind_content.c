/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfind_content.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 20:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 20:16:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_content(t_list *lst, void *content)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL && ft_memcmp(lst->content, content) != 0)
		lst = lst->next;
	return (lst);
}
