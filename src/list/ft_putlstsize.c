/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlstsize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:11:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "ft/num.h"
#include "ft/char.h"

#include "list.h"

bool	ft_putlstsize(const t_list *lst)
{
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (ft_putnum(lst->content_size) == false)
		return (false);
	if (ft_putchar('\n') == false)
		return (false);
	if (lst->next != NULL)
		return (ft_putlstsize(lst->next));
	return (true);
}
