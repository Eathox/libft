/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putunum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putunum(t_info *info)
{
	t_intmax	num;

	if (PF_PRECISION >= 0 && pf_iszero(info))
	{
		if (PF_PRECISION > 0 || (PF_TYPE == 'o' && PF_FLAG_HASH))
			pf_putchar(info, '0');
		else if (PF_WIDTH > 0)
			pf_putchar(info, ' ');
		return ;
	}
	num = pf_overflowunsigned(info);
	ft_putunbr_cbase(num, PF_VAR_BASE, PF_TYPE == 'X');
	PF_PRINTED += PF_VAR_LEN;
}
