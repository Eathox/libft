/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 13:56:40 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:31:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	ft_lstadd(t_list **head, t_list *new)
{
	new->next = *head;
	*head = new;
}
