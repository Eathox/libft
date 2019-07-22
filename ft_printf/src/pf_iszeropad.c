/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_iszeropad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 17:27:00 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:59:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	pf_iszeropad(t_info *info)
{
	if (info->precision != -1 && info->var_len != 0 &&
		info->var_len >= info->precision)
		return (FALSE);
	return (PF_FLAG_ZERO || (info->precision != -1 && pf_isstr(info) == FALSE));
}
