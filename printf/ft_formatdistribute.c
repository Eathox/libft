/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatdistribute.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "priv.h"

void	ft_formatdistribute(t_info *info)
{
	if (ft_issignint(info))
		ft_formatnum(info);
	else if (ft_isunsignint(info))
		ft_formatunum(info);
	else if (info->var_type == CHAR || info->var_type == T_WCHAR)
		ft_formatchar(info);
	else if (ft_isstr(info))
		ft_formatstr(info);
	else if (info->var_type == DOUBLE || info->var_type == LONG_DOUBLE)
		ft_formatdouble(info);
	ft_formatbackpad(info);
}
