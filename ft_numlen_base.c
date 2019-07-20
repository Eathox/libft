/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 19:53:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_numlen_base(intmax_t value, int base)
{
	uintmax_t	num;

	num = (value < 0 && base == 10) ? -value : value;
	return (ft_unumlen_base(num, base) + (value < 0 && base == 10));
}
