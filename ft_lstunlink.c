/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:41:05 by pholster       #+#    #+#                */
/*   Updated: 2019/02/18 17:45:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstunlink(t_list **alst, t_list *lst)
{
	if (alst == NULL || lst == NULL)
		return (NULL);
	while (alst[0]->next != lst)
		alst[0] = alst[0]->next;
	alst[0]->next = lst->next;
	return (lst);
}
