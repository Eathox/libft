/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clearterminal.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 14:51:28 by pholster       #+#    #+#                */
/*   Updated: 2019/01/26 14:51:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clearterminal(void)
{
	write(0, "\e[1;1H\e[2J", 12);
}
