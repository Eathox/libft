/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_inrange.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:32:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

t_bool	ft_inrange(intmax_t value, intmax_t min, intmax_t max)
{
	if (value < min || value > max)
		return (FALSE);
	return (TRUE);
}
