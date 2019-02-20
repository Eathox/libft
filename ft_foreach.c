/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_foreach.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:40:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(const int *arr, int length, void (*f)(int))
{
	int	i;

	i = 0;
	if (f == NULL || arr == NULL)
		return ;
	while (i < length)
	{
		f(arr[i]);
		i++;
	}
}
