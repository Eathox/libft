/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_format.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:59:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	pf_format(t_info *info)
{
	if (pf_issignint(info))
		pf_formatnum(info);
	else if (pf_isunsignint(info))
		pf_formatunum(info);
	else if (info->var_type == CHAR || info->var_type == T_WCHAR)
		pf_formatchar(info);
	else if (pf_isstr(info))
		pf_formatstr(info);
	else if (info->var_type == DOUBLE || info->var_type == LONG_DOUBLE)
		pf_formatdouble(info);
	pf_formatbackpad(info);
}
