/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatbackpad.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:26:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/num.h"

#include "printf.h"
#include "priv.h"

void		ft_formatbackpad(t_info *info) {
	intmax_t	len;
	intmax_t	i;

	i = info->padadded;
	len = ft_max(0, info->width) - info->var_len;
	if (PF_FLAG_MIN == false)
		return ;
	while (i < len)
	{
		ft_addtobuff(info, " ", 1);
		i++;
	}
}
