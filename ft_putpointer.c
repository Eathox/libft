/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 00:11:56 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 11:02:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpointer(const void *pointer)
{
	if (pointer == NULL)
		ft_putstr("0x");
	else
		ft_putstr("0x10");
	ft_putnbr_base((int)pointer, 16);
}
