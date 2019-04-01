/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printdouble.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:06:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_printdouble(t_info *info)
{
	if (PF_VAR_TYPE == DOUBLE)
		ft_putdouble_fd(PF_VAR_DOUBLE, PF_PRECISION, PF_FD);
	else
		ft_putdouble_fd(PF_VAR_LDOUBLE, PF_PRECISION, PF_FD);
	PF_PRINTED += PF_VAR_LEN;
}
