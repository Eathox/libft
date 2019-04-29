/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setcolor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 15:45:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_setcolor(t_info *info, int color)
{
	if (color < 0 || color > 255)
	{
		pf_addtobuff(info, "\e[39m\e[K", 9);
		return ;
	}
	pf_addtobuff(info, "\e[38;5;", 8);
	pf_addnum(info, color);
	pf_addtobuff(info, "m", 1);
}
