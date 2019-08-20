/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:43:05 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 01:50:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

intmax_t		ft_abs(intmax_t num)
{
	if (num < 0)
		return (-num);
	return (num);
}
