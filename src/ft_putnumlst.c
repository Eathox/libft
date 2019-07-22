/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnumlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void	ft_putnumlst(t_list *lst)
{
	intmax_t	*n;

	if (lst == NULL)
		return ;
	n = (intmax_t *)lst->content;
	ft_putnum(*n);
	write(1, "\n", 1);
	if (lst->next != NULL)
		ft_putnumlst(lst->next);
}
