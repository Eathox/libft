/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lststrsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:28:11 by pholster       #+#    #+#                */
/*   Updated: 2019/03/16 22:47:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lststrsort(t_list *sortlst, t_list *lst)
{
	size_t		n;

	n = ft_max(sortlst->content_size, lst->content_size);
	return (ft_memcmp(sortlst->content, lst->content, n ) > 0);
}
