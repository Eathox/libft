/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsortstrac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:28:11 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool		ft_lstsortstrac(t_list *sortlst, t_list *lst)
{
	int		result;
	size_t	n;

	n = ft_max(sortlst->content_size, lst->content_size);
	result = ft_memcmp(sortlst->content, lst->content, n);
	return (result > 0 && result != 0);
}
