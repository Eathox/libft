/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnum_base(intmax_t value, int base)
{
	ft_putnum_cbase_fd(value, base, TRUE, 1);
}
