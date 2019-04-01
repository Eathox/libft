/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getinfo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	checkinfo(va_list args, t_info *info, const char *str)
{
	if (ft_chrin(PF_A_FLAG, *str) || ft_chrin(PF_A_SPACER, *str))
		return (pf_getflag(info, str));
	else if (ft_isdigit(*str) || *str == '*')
		return (pf_getwidth(args, info, str));
	else if (*str == '.')
		return (pf_getprecision(args, info, str));
	else if (ft_chrin(PF_A_LENGTH, *str) ||
		(ft_chrin(PF_A_LENGTH_D, PF_LENGTH) && *str == PF_LENGTH))
		return (pf_getlength(info, str));
	else if (ft_chrin(PF_A_TYPE, *str) || ft_chrin(PF_A_TYPE_L, *str))
		return (pf_gettype(info, str));
	return (0);
}

static void	setvar(va_list args, t_info *info)
{
	if (PF_VAR_TYPE == DOUBLE)
		PF_VAR_DOUBLE = va_arg(args, double);
	else if (PF_VAR_TYPE == LONG_DOUBLE)
		PF_VAR_LDOUBLE = va_arg(args, long double);
	else if (PF_TYPE != '%' && ft_chrin(PF_A_TYPE, PF_TYPE))
		PF_VAR = va_arg(args, void *);
}

int			pf_getinfo(va_list args, t_info *info, const char *str)
{
	int	ret;
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != '\n')
	{
		ret = checkinfo(args, info, &str[i]);
		if (ret == 0 || ret == -1)
			break ;
		i += ret;
	}
	pf_setvar_type(info);
	setvar(args, info);
	if (PF_TYPE == 'f' && PF_PRECISION == -1)
		PF_PRECISION = 6;
	else if (PF_VAR_TYPE == CHAR || PF_VAR_TYPE == T_WCHAR)
		PF_PRECISION = -1;
	pf_setvar_base(info);
	pf_setvar_len(info);
	return (i + (ret == -1));
}
