/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:13:48 by pholster       #+#    #+#                */
/*   Updated: 2019/02/10 11:44:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_pow(long long n, long long pow)
{
	long long	ret;

	ret = n;
	if (pow == 0)
		return (1);
	if (pow == 1 && n < 0)
		return (n);
	if (pow < 0)
		return (0);
	if (n < 0)
		n = -n;
	if (ret < 0)
		ret = -ret;
	while (pow > 1)
	{
		pow--;
		ret *= n;
	}
	return (ret);
}
