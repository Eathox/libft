/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_iszeropad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 17:27:00 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 16:28:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	pf_iszeropad(t_info *info)
{
	if (PF_PRECISION != -1 && PF_VAR_LEN >= PF_PRECISION && PF_VAR_LEN != 0)
		return (FALSE);
	return (PF_FLAG_ZERO || (PF_PRECISION != -1 && pf_isstr(info) == FALSE));
}
