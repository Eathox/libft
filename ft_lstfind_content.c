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
	if (lst == NULL || content == NULL)
		return (NULL);
	while (ft_memcmp(lst->content, content) != 0 && lst != NULL)
		lst = lst->next;
	return (lst);
}
