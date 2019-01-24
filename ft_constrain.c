/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_constrain.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/01/19 12:44:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_constrain(int n, int min, int max)
{
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}
