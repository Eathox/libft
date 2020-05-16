/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:11:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

#include "list.h"

bool	ft_putstrlst(const t_list *lst)
{
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (ft_putendl((char *)lst->content) == false)
		return (false);
	if (lst->next != NULL)
		return (ft_putstrlst(lst->next));
	return (false);
}
