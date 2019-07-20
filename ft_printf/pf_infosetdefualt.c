/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_infosetdefualt.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 22:18:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_infosetdefualt(t_info *info)
{
	info->length = -1;
	info->precision = -1;
	info->type = -1;
	info->width = -1;
	info->var_len = -1;
	info->var_type = -1;
	info->var_base = -1;
	info->padadded = 0;
	PF_FLAG_HASH = FALSE;
	PF_FLAG_ZERO = FALSE;
	PF_FLAG_MIN = FALSE;
	PF_FLAG_PLUS = FALSE;
	PF_FLAG_SPACE = FALSE;
	PF_FLAG_APOST = FALSE;
	info->iszero = FALSE;
	info->isnegative = FALSE;
}
