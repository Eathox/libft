/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setvar_len.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:04:29 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_setvar_len(t_info *info)
{
	if (pf_issignint(info))
		pf_getsignedlen(info);
	else if (pf_isunsignint(info))
		pf_getunsignedlen(info);
	else if (PF_VAR_TYPE == DOUBLE || PF_VAR_TYPE == LONG_DOUBLE)
		pf_getdoublelen(info);
	else if (PF_VAR_TYPE == T_WCHAR_STR)
		pf_getutf8strlen(info);
	else if (PF_VAR_TYPE == STR)
		pf_getstrlen(info);
	else if (PF_VAR_TYPE == T_WCHAR)
		PF_VAR_LEN = ft_utf8len(PF_GVAR(t_wchar));
	else if (PF_VAR_TYPE == CHAR)
		PF_VAR_LEN = 1;
	else
		PF_VAR_LEN = 1;
	if (pf_isnegative(info))
		PF_VAR_LEN--;
}
