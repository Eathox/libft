/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addunum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 02:16:09 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 16:04:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_addunum(t_info *info, t_uintmax value, int len, int base)
{
	char	c;
	char	*base_str;

	if (len == 0)
		return ;
	if (PF_TYPE == 'X')
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (len > 1)
		pf_addunum(info, value / base, len - 1, base);
	c = base_str[(value % base)];
	pf_addtobuff(info, &c, 1);
}
