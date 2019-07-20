/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 13:00:18 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 20:46:46 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool		pf_isstr(t_info *info)
{
	return (info->var_type == STR || info->var_type == T_WCHAR_STR);
}
