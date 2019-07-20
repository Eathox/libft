/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_overflowsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 18:15:52 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 16:12:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	pf_overflowsigned(t_info *info)
{
	if (PF_VAR_TYPE == LONG)
		return (va_arg(PF_ARGS, long));
	if (PF_VAR_TYPE == LONG_LONG)
		return (va_arg(PF_ARGS, long long));
	if (PF_VAR_TYPE == INT_MAX)
		return (va_arg(PF_ARGS, intmax_t));
	if (PF_VAR_TYPE == CHAR_I)
		return ((char)va_arg(PF_ARGS, int));
	if (PF_VAR_TYPE == SHORT)
		return ((short)va_arg(PF_ARGS, int));
	return (va_arg(PF_ARGS, int));
}
