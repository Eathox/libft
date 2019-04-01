/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_printstr(t_info *info)
{
	if (PF_VAR_TYPE == STR)
		pf_putnstr(info, PF_GVAR(char *), PF_VAR_LEN);
	else
		pf_putnutf8str(info, PF_GVAR(t_wchar *), PF_VAR_LEN);
}
