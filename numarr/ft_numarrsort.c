/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numarrsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:21:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "numarr.h"

void	ft_numarrsort(intmax_t *arr,
	t_bool (*f)(intmax_t, intmax_t), size_t len)
{
	size_t		i;
	size_t		j;
	intmax_t	current;

	i = 1;
	while (i < len)
	{
		j = i;
		current = arr[i];
		while (j > 0 && f(current, arr[j - 1]))
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
