/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 00:11:56 by pholster       #+#    #+#                */
/*   Updated: 2019/07/14 14:45:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putpointer(const void *pointer)
{
	ft_putstr("0x");
	ft_putnbr_cbase((size_t)pointer, 16, FALSE);
}
