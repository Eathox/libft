/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:41:05 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:11:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstunlink(t_list **head, t_list *lst) {
	t_list	*current;

	if (*head == lst)
	{
		*head = lst->next;
		lst->next = NULL;
		return (lst);
	}
	current = *head;
	while (current != NULL && current->next != lst)
		current = current->next;
	if (current == NULL)
		return (NULL);
	current->next = lst->next;
	lst->next = NULL;
	return (lst);
}
