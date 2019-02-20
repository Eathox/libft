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

int		ft_intin(const int *arr, int n, int len)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (FALSE);
	while (i < len)
	{
		if (arr[i] == n)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
