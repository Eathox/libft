/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print(t_info *info)
{
	pf_printpad(info);
	if (pf_issignint(info))
		pf_putnum(info);
	else if (pf_isunsignint(info))
		pf_putunum(info);
	else if (PF_VAR_TYPE == CHAR || PF_VAR_TYPE == T_WCHAR)
		pf_printchar(info);
	else if (pf_isstr(info))
		pf_printstr(info);
	else if (PF_VAR_TYPE == DOUBLE || PF_VAR_TYPE == LONG_DOUBLE)
		pf_printdouble(info);
	pf_printbackpad(info);
}
