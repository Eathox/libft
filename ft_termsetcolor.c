/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolor.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/03/19 17:41:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termsetcolor(int color)
{
	if (color < 0)
	{
		ft_termresetcolor();
		return ;
	}
	ft_putstr("\e[38;5;");
	ft_putnbr(color);
	ft_putchar('m');
}
