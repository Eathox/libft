/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlstsize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 18:14:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_putlstsize(t_list *lst)
{
	if (lst == NULL)
		return (TRUE);
	if (ft_putnum(lst->content_size) == FALSE)
		return (FALSE);
	if (ft_putchar('\n') == FALSE)
		return (FALSE);
	if (lst->next != NULL)
		return (ft_putlstsize(lst->next));
	return (TRUE);
}
