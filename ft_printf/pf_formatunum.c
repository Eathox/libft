/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatunum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/24 13:10:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	itoa(t_info *info, t_uintmax value)
{
	int		len;
	char	*base_str;
	char	*str;

	len = PF_VAR_LEN;
	if (len == 0)
		return ;
	if (PF_TYPE == 'X')
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	str = ft_strnew(len);
	if (str == NULL)
		return ;
	while (len != 0)
	{
		len--;
		str[len] = base_str[(value % PF_VAR_BASE)];
		value /= PF_VAR_BASE;
	}
	pf_addtobuff(info, str, PF_VAR_LEN);
	free(str);
}

void		pf_formatunum(t_info *info)
{
	t_uintmax	num;

	num = pf_overflowunsigned(info);
	PF_ISZERO = (num == 0);
	PF_VAR_LEN = ft_unumlen_base(num, PF_VAR_BASE);
	pf_formatpad(info);
	if (PF_PRECISION >= 0 && PF_ISZERO)
	{
		if (PF_PRECISION > 0 || (PF_TYPE == 'o' && PF_FLAG_HASH))
			pf_addnstr(info, "0", 1);
		else if (PF_WIDTH > 0)
			pf_addnstr(info, " ", 1);
		return ;
	}
	itoa(info, num);
}
