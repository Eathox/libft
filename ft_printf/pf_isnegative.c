/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isnegative.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:55:05 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_isnegative(t_info *info)
{
	if (PF_VAR_TYPE == SHORT)
		return (PF_GVAR(short) < 0);
	if (PF_VAR_TYPE == INT)
		return (PF_GVAR(int) < 0);
	if (PF_VAR_TYPE == INT_MAX)
		return (PF_GVAR(t_intmax) < 0);
	if (PF_VAR_TYPE == LONG)
		return (PF_GVAR(long) < 0);
	if (PF_VAR_TYPE == LONG_LONG)
		return (PF_GVAR(long long) < 0);
	if (PF_VAR_TYPE == CHAR_I)
		return (PF_GVAR(char) < 0);
	return (FALSE);
}
