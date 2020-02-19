/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getinfo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:28:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/printf.h"
#include "priv.h"
#include "ft/char.h"

static int	checkinfo(t_info *info, const char *str)
{
	if (ft_chrin(PF_A_FLAG, *str) || ft_chrin(PF_A_SPACER, *str))
		return (ft_getflag(info, str));
	else if (ft_isdigit(*str) || *str == '*')
		return (ft_getwidth(info, str));
	else if (*str == '.')
		return (ft_getprecision(info, str));
	else if (ft_chrin(PF_A_LENGTH, *str) ||
		(ft_chrin(PF_A_LENGTH_D, info->length) && *str == info->length))
		return (ft_getlength(info, str));
	else if (ft_chrin(PF_A_TYPE, *str) || ft_chrin(PF_A_TYPE_L, *str))
		return (ft_gettype(info, str));
	return (0);
}

size_t		ft_getinfo(t_info *info, const char *str)
{
	int		ret;
	size_t	i;

	i = 0;
	ret = 1;
	while ((str[i] != '\0' || str[i] != '\n') && ret > 0)
	{
		ret = checkinfo(info, &str[i]);
		if (ret > 0)
			i += ret;
	}
	ft_setvar_type(info);
	if (info->type == 'f' && info->precision == -1)
		info->precision = 6;
	else if (info->var_type == CHAR || info->var_type == T_WCHAR)
		info->precision = -1;
	ft_setvar_base(info);
	return (i + (ret == -1));
}
