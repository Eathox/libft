/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addcolorbg.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "priv.h"

void	ft_addcolorbg(t_info *info, int color)
{
	if (color < 0 || color > 255)
	{
		ft_addtobuff(info, "\033[49m\033[K", 8);
		return ;
	}
	ft_addtobuff(info, "\033[48;5;", 7);
	ft_addnum(info, color);
	ft_addtobuff(info, "m", 1);
}
