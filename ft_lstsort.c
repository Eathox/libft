/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:08:43 by pholster       #+#    #+#                */
/*   Updated: 2019/04/06 01:22:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstjoin(t_list *head, t_list *half,
	int (*f)(t_list *, t_list *))
{
	if (head == NULL)
		return (half);
	if (half == NULL)
		return (head);
	if (f(head, half))
	{
		half->next = lstjoin(head, half->next, f);
		return (half);
	}
	head->next = lstjoin(head->next, half, f);
	return (head);
}

void			ft_lstsort(t_list **head, int (*f)(t_list *, t_list *))
{
	t_list	*lst;
	t_list	*half;
	t_list	*temp;

	if (f == NULL || head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	lst = *head;
	temp = ft_lstindex(lst, (ft_lstlen(lst) - 1) / 2);
	half = temp->next;
	temp->next = NULL;
	ft_lstsort(&lst, f);
	ft_lstsort(&half, f);
	*head = lstjoin(lst, half, f);
}
