/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_infosetdefualt.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_infosetdefualt(t_info *info)
{
	PF_LENGTH = -1;
	PF_PRECISION = -1;
	PF_TYPE = -1;
	PF_WIDTH = -1;
	PF_VAR = NULL;
	PF_VAR_DOUBLE = 0;
	PF_VAR_LDOUBLE = 0;
	PF_VAR_LEN = -1;
	PF_VAR_TYPE = -1;
	PF_VAR_BASE = -1;
	PF_PADPRINTED = 0;
	PF_FLAG_HASH = 0;
	PF_FLAG_ZERO = 0;
	PF_FLAG_MIN = 0;
	PF_FLAG_PLUS = 0;
	PF_FLAG_SPACE = 0;
	PF_FLAG_APOST = 0;
}
