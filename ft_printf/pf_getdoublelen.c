/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getdoublelen.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 12:27:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_getdoublelen(t_info *info)
{
	if (PF_VAR_TYPE == DOUBLE)
		PF_VAR_LEN = ft_numlen((long)PF_VAR_DOUBLE) + PF_PRECISION;
	else
		PF_VAR_LEN = ft_numlen((long)PF_VAR_LDOUBLE) + PF_PRECISION;
	if (PF_PRECISION > 0)
		PF_VAR_LEN++;
}
