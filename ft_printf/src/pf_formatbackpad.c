/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatbackpad.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:59:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

void		pf_formatbackpad(t_info *info)
{
	intmax_t	len;
	intmax_t	i;

	i = info->padadded;
	len = ft_max(0, info->width) - info->var_len;
	if (PF_FLAG_MIN == FALSE)
		return ;
	while (i < len)
	{
		pf_addtobuff(info, " ", 1);
		i++;
	}
}
