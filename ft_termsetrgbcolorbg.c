/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetrgbcolorbg.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/03/19 20:17:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termsetrgbcolorbg(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_termresetcolorbg();
		return ;
	}
	ft_putstr("\e[48;2;");
	ft_putnbr(r);
	ft_putchar(';');
	ft_putnbr(g);
	ft_putchar(';');
	ft_putnbr(b);
	ft_putchar('m');
}
