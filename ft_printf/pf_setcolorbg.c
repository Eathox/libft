/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setcolorbg.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 15:45:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_setcolorbg(t_info *info, int color)
{
	if (color < 0 || color > 255)
	{
		pf_addtobuff(info, "\e[49m\e[K", 9);
		return ;
	}
	pf_addtobuff(info, "\e[48;5;", 8);
	pf_addnum(info, color);
	pf_addtobuff(info, "m", 1);
}
