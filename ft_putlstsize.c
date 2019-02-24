/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlstsize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 14:34:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlstsize(t_list *lst)
{
	if (lst == NULL)
		return ;
	ft_putnbr(lst->content_size);
	write(1, "\n", 1);
	if (lst->next != NULL)
		ft_putlstsize(lst->next);
}
