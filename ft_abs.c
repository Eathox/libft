/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:43:05 by pholster       #+#    #+#                */
/*   Updated: 2019/02/09 12:40:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_abs(long n)
{
	unsigned long num;

	num = (n < 0) ? -n : n;
	return (num);
}
