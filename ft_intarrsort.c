/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/03/15 15:15:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intarrsort(int *arr, size_t n)
{
	size_t	i;
	int		j;
	int		current;

	i = 1;
	while (i < n)
	{
		j = i - 1;
		current = arr[i];
		while (j >= 0 && arr[j] > current)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
		i++;
	}
}
