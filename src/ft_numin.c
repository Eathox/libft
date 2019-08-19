/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:41:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

t_bool	ft_numin(const intmax_t *arr, intmax_t num, size_t len)
{
	while (len > 0)
	{
		len--;
		if (arr[len] == num)
			return (TRUE);
	}
	return (FALSE);
}
