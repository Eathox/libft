/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 00:11:56 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 18:18:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_putpointer(const void *pointer)
{
	if (ft_putstr("0x") == FALSE)
		return (FALSE);
	return (ft_putnum_cbase((size_t)pointer, 16, FALSE));
}
