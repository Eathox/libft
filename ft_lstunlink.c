/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:41:05 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstunlink(t_list *head, t_list *lst)
{
	t_list	*current;

	current = head;
	while (current != NULL && current->next != lst)
		current = current->next;
	if (current == NULL || lst == NULL || current == lst)
		return (NULL);
	current->next = lst->next;
	return (lst);
}
