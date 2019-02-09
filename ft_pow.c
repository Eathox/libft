/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:13:48 by pholster       #+#    #+#                */
/*   Updated: 2019/02/09 12:41:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(long n, long pow)
{
	long	r;

	r = n;
	if (pow == 0)
		return (1);
	if (pow == 1 && n < 0)
		return (n);
	if (pow < 0)
		return (0);
	if (n < 0)
		n = -n;
	if (r < 0)
		r = -r;
	while (pow > 1)
	{
		pow--;
		r = r * n;
	}
	if (r > 2147483647)
		return (1);
	return ((int)r);
}
