/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setvar_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 11:12:01 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_setvar_base(t_info *info)
{
	if (ft_chrin("diuf", PF_TYPE))
		PF_VAR_BASE = 10;
	else if (ft_chrin("xXaA", PF_TYPE) || PF_TYPE == 'p')
		PF_VAR_BASE = 16;
	else if (PF_TYPE == 'o')
		PF_VAR_BASE = 8;
	else if (PF_TYPE == 'b')
		PF_VAR_BASE = 2;
	else
		PF_VAR_BASE = -1;
}
