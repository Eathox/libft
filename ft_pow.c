/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:13:48 by pholster      #+#    #+#                 */
/*   Updated: 2019/01/11 21:00:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int pow)
{
	long long	r;

	r = n;
	if (pow == 0 || n == -2147483648)
		return (1);
	if (pow == 1 && n < 0)
		return (n);
	if (pow < 0)
		return (0);
	if (r < 0)
		n = -n;
	if (r < 0)
		r = -r;
	while (pow-- > 1)
		r = r * n;
	if (r > 2147483647)
		return (1);
	return (r);
}
