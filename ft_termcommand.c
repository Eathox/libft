/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termcommand.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 12:21:06 by pholster       #+#    #+#                */
/*   Updated: 2019/03/19 12:25:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termcommand(int command)
{
	ft_putstr("\e[");
	ft_putnbr(command);
	ft_putchar('m');
}
