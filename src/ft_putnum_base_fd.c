/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum_base_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnum_base_fd(intmax_t value, int base, int fd)
{
	ft_putnum_cbase_fd(value, base, TRUE, fd);
}
