/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddbck.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:28:18 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:31:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	ft_lstaddbck(t_list **head, t_list *new)
{
	t_list	*lst;

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
