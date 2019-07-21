/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum_cbase.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnum_cbase(intmax_t value, int base, t_bool up)
{
	ft_putnum_cbase_fd(value, base, up, 1);
}
