/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_overflowunsigned.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 18:15:52 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uintmax	pf_overflowunsigned(t_info *info)
{
	if (PF_VAR_TYPE == U_LONG || PF_VAR_TYPE == VOID)
		return (PF_GVAR(unsigned long));
	if (PF_VAR_TYPE == U_LONG_LONG)
		return (PF_GVAR(unsigned long long));
	if (PF_VAR_TYPE == U_INT_MAX)
		return (PF_GVAR(t_uintmax));
	if (PF_VAR_TYPE == U_CHAR_I)
		return (PF_GVAR(unsigned char));
	if (PF_VAR_TYPE == U_SHORT)
		return (PF_GVAR(unsigned short));
	if (PF_VAR_TYPE == SIZE_T)
		return (PF_GVAR(size_t));
	return (PF_GVAR(unsigned int));
}
