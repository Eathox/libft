/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printchar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_printchar(t_info *info)
{
	if (PF_VAR_TYPE == T_WCHAR)
		pf_putwchar(info, PF_GVAR(t_wchar));
	else if (PF_TYPE == '%')
		pf_putchar(info, '%');
	else if (PF_TYPE == 'c')
		pf_putchar(info, PF_GVAR(char));
}
