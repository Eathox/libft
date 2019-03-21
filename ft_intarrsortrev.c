/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrsortrev.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/03/21 21:49:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intarrsortrev(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	int		current;

	i = 1;
	if (arr == NULL)
		return ;
	while (i < len)
	{
		j = i;
		current = arr[i];
		while (j > 0 && arr[j - 1] < current)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
