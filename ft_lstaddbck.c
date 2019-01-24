/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddbck.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:28:18 by pholster       #+#    #+#                */
/*   Updated: 2019/01/14 20:19:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddbck(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	if (alst[0]->next == NULL)
		alst[0]->next = new;
	else
		ft_lstaddbck(&alst[0]->next, new);
}
