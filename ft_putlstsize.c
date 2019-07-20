/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlstsize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 20:19:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putlstsize(t_list *lst)
{
	if (lst == NULL)
		return ;
	ft_putnum(lst->content_size);
	write(1, "\n", 1);
	if (lst->next != NULL)
		ft_putlstsize(lst->next);
}
