/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:18:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

t_bool	ft_numin(const intmax_t *arr, intmax_t num, size_t len)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (FALSE);
	while (i < len)
	{
		if (arr[i] == num)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
