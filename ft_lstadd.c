/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 13:56:40 by pholster       #+#    #+#                */
/*   Updated: 2019/03/16 22:53:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **head, t_list *new)
{
	if (head == NULL || *head == NULL || new == NULL)
		return ;
	new->next = *head;
	*head = new;
}
