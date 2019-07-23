/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfind_size.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 20:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:15:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

t_list	*ft_lstfind_size(t_list *lst, size_t size)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL && lst->content_size != size)
		lst = lst->next;
	return (lst);
}
