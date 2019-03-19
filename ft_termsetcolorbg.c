/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolorbg.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/03/19 20:17:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termsetcolorbg(int color)
{
	if (color < 0 || color > 255)
	{
		ft_termresetcolorbg();
		return ;
	}
	ft_putstr("\e[48;5;");
	ft_putnbr(color);
	ft_putchar('m');
}
