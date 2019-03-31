/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_iszero.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:30:59 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_iszero(t_info *info)
{
	if (PF_VAR_TYPE == SHORT)
		return (PF_GVAR(short) == 0);
	if (PF_VAR_TYPE == INT)
		return (PF_GVAR(int) == 0);
	if (PF_VAR_TYPE == LONG)
		return (PF_GVAR(long) == 0);
	if (PF_VAR_TYPE == LONG_LONG)
		return (PF_GVAR(long long) == 0);
	if (PF_VAR_TYPE == INT_MAX)
		return (PF_GVAR(t_intmax) == 0);
	if (PF_VAR_TYPE == CHAR_I)
		return (PF_GVAR(char) == 0);
	if (PF_VAR_TYPE == U_INT || PF_VAR_TYPE == U_SHORT)
		return (PF_GVAR(unsigned int) == 0);
	if (PF_VAR_TYPE == U_LONG || PF_VAR_TYPE == VOID)
		return (PF_GVAR(unsigned long) == 0);
	if (PF_VAR_TYPE == U_LONG_LONG)
		return (PF_GVAR(unsigned long long) == 0);
	if (PF_VAR_TYPE == U_INT_MAX)
		return (PF_GVAR(t_uintmax) == 0);
	if (PF_VAR_TYPE == U_CHAR_I)
		return (PF_GVAR(unsigned char) == 0);
	if (PF_VAR_TYPE == SIZE_T)
		return (PF_GVAR(size_t) == 0);
	return (FALSE);
}
