/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:43:05 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 20:18:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

intmax_t		ft_abs(intmax_t num)
{
	uintmax_t temp_num;

	temp_num = (num < 0) ? -num : num;
	return (temp_num);
}
