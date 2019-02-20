/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdupone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:54:49 by pholster       #+#    #+#                */
/*   Updated: 2019/01/13 16:03:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdupone(const t_list *lst)
{
	t_list	*duplst;

	if (lst == NULL)
		return (NULL);
	duplst = ft_lstnew(lst->content, lst->content_size);
	if (duplst == NULL)
		return (NULL);
	return (duplst);
}
