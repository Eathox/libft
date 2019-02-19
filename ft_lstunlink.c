/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:41:05 by pholster       #+#    #+#                */
/*   Updated: 2019/02/19 15:29:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstunlink(t_list *head, t_list *lst)
{
	while (head != NULL && head->next != lst)
		head = head->next;
	if (head == NULL || lst == NULL || head == lst)
		return (NULL);
	head->next = lst->next;
	return (lst);
}
