/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_lstaddptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 01:30:30 by pholster       #+#    #+#                */
/*   Updated: 2019/04/12 12:22:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_lstaddptr(t_info *info, char *str, size_t len)
{
	t_list		*lst;

	if (str == NULL)
		return ;
	lst = ft_lstnew(NULL, 0);
	if (lst == NULL)
		return ;
	lst->content = str;
	lst->content_size = len;
	pf_lstadd(info, lst);
}
