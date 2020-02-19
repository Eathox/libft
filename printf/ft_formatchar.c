/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatchar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:26:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/printf.h"
#include "priv.h"

void	ft_formatchar(t_info *info)
{
	t_wchar	c;

	if (info->var_type == T_WCHAR || info->type == 'c')
		c = va_arg(info->args, t_wchar);
	else
		c = '%';
	info->var_len = ft_utf8len(c);
	ft_formatpad(info);
	if (info->var_type == T_WCHAR)
		ft_addwchar(info, c);
	else if (info->type == '%')
		ft_addnstr(info, "%", 1);
	else if (info->type == 'c')
		ft_addchar(info, (char)c);
}
