/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_iszeropad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 17:27:00 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_iszeropad(t_info *info)
{
	if (PF_PRECISION != -1 && PF_VAR_LEN >= PF_PRECISION && PF_VAR_LEN != 0)
		return (FALSE);
	return (PF_FLAG_ZERO || (PF_PRECISION != -1 && pf_isstr(info) == FALSE));
}
