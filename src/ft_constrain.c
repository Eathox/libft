/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_constrain.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:38:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

intmax_t	ft_constrain(intmax_t value, intmax_t min, intmax_t max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
