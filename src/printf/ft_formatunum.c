/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatunum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:28:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/unum.h"

#include "printf.h"
#include "priv.h"

void		ft_formatunum(t_info *info)
{
	uintmax_t	num;

	num = ft_overflowunsigned(info);
	info->is_zero = (num == 0);
	info->var_len = ft_unumlen_base(num, info->var_base);
	ft_formatpad(info);
	if (info->precision >= 0 && info->is_zero)
	{
		if (info->precision > 0 ||
			(info->type == 'o' && PF_FLAG_HASH))
			ft_addnstr(info, "0", 1);
		else if (info->width > 0)
			ft_addnstr(info, " ", 1);
		return ;
	}
	ft_addunum(info, num, info->var_len, info->var_base);
}
