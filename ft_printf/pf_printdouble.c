/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printdouble.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_printdouble(t_info *info)
{
	if (PF_VAR_TYPE == DOUBLE)
		ft_putdouble(PF_VAR_DOUBLE, PF_PRECISION);
	else
		ft_putdouble(PF_VAR_LDOUBLE, PF_PRECISION);
	PF_PRINTED += PF_VAR_LEN;
}
