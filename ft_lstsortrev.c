/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsortrev.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:08:43 by pholster       #+#    #+#                */
/*   Updated: 2019/03/23 00:04:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	spawhead(t_list **head, t_list *sortlst, t_list *prvsort)
{
	if (sortlst != *head)
	{
		prvsort->next = sortlst->next;
		sortlst->next = *head;
		*head = sortlst;
	}
}

void		ft_lstsortrev(t_list **head, int (*f)(t_list *, t_list *))
{
	t_list	*lst;
	t_list	*prvlst;
	t_list	*sortlst;
	t_list	*prvsort;

	if (head == NULL || *head == NULL || f == NULL)
		return ;
	lst = (*head)->next;
	prvlst = *head;
	sortlst = *head;
	while (lst != NULL)
	{
		if (f(sortlst, lst) == FALSE)
		{
			prvsort = prvlst;
			sortlst = lst;
		}
		prvlst = lst;
		lst = lst->next;
	}
	spawhead(head, sortlst, prvsort);
	if ((*head)->next != NULL && (*head)->next->next != NULL)
		ft_lstsortrev(&(*head)->next, f);
}
