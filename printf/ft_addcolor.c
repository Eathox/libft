/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addcolor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/printf.h"
#include "priv.h"

void	ft_addcolor(t_info *info, int color)
{
	if (color < 0 || color > 255)
	{
		ft_addtobuff(info, "\033[39m\033[K", 8);
		return ;
	}
	ft_addtobuff(info, "\033[38;5;", 7);
	ft_addnum(info, color);
	ft_addtobuff(info, "m", 1);
}
