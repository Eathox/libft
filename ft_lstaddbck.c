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

void	ft_lstaddbck(const t_list *lst, const t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (lst->next == NULL)
		lst->next = new;
	else
		ft_lstaddbck(lst->next, new);
}
