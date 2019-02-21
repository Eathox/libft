/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:46:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intin(const int *arr, int num, size_t n)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (FALSE);
	while (i < n)
	{
		if (arr[i] == num)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
