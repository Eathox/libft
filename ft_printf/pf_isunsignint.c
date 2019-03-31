/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isunsignint.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:52:53 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isunsignint(t_info *info)
{
	if (PF_VAR_TYPE == U_INT || PF_VAR_TYPE == U_SHORT)
		return (TRUE);
	if (PF_VAR_TYPE == U_INT_MAX || PF_VAR_TYPE == SIZE_T)
		return (TRUE);
	if (PF_VAR_TYPE == U_LONG || PF_VAR_TYPE == U_LONG_LONG)
		return (TRUE);
	if (PF_VAR_TYPE == U_CHAR_I || PF_VAR_TYPE == VOID)
		return (TRUE);
	return (FALSE);
}
