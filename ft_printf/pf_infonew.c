/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_infonew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:28:28 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 12:42:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*pf_infonew(void)
{
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	pf_infosetdefualt(info);
	PF_PRINTED = 0;
	PF_FD = 1;
	return (info);
}
