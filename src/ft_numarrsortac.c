/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numarrsortac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 23:47:03 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:37:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

t_bool		ft_numarrsortac(intmax_t current, intmax_t num)
{
	return (current < num && current - num != 0);
}
