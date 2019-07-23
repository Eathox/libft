/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddbck.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:28:18 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:14:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

void	ft_lstaddbck(t_list **head, t_list *new)
{
	t_list	*lst;

	if (head == NULL || new == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}
