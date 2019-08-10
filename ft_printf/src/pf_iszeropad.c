/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_iszeropad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 17:27:00 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	pf_iszeropad(t_info *info)
{
	if (info->precision != -1 && info->var_len != 0 &&
		info->var_len >= info->precision)
		return (FALSE);
	return (PF_FLAG_ZERO || (info->precision != -1 && pf_isstr(info) == FALSE));
}
