/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 01:30:30 by pholster       #+#    #+#                */
/*   Updated: 2019/04/12 01:30:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_lstadd(t_info *info, t_list *lst)
{
	if (PF_HEAD == NULL)
		PF_HEAD = lst;
	else
		PF_LST->next = lst;
	if (lst != NULL)
		PF_LST = lst;
}
