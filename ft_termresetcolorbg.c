/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termresetcolorbg.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/03/18 15:09:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termresetcolorbg(void)
{
	ft_putstr("\e[49m\e[K");
}
