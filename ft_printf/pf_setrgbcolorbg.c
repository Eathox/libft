/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setrgbcolorbg.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 15:40:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_setrgbcolorbg(t_info *info, int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		pf_addtobuff(info, "\e[49m\e[K", 9);
		return ;
	}
	pf_addtobuff(info, "\e[48;2;", 8);
	pf_addnum(info, r);
	pf_addtobuff(info, ";", 1);
	pf_addnum(info, g);
	pf_addtobuff(info, ";", 1);
	pf_addnum(info, b);
	pf_addtobuff(info, "m", 1);
}
