/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetrgbcolor.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/03/19 17:55:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termsetrgbcolor(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0)
	{
		ft_termresetcolor();
		return ;
	}
	ft_putstr("\e[38;2;");
	ft_putnbr(r);
	ft_putchar(';');
	ft_putnbr(g);
	ft_putchar(';');
	ft_putnbr(b);
	ft_putchar('m');
}
