/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_foreach.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:23:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(const int *arr, int length, void (*f)(int))
{
	size_t	i;

	i = 0;
	if (f == NULL || arr == NULL)
		return ;
	while (i < (size_t)length)
	{
		f(arr[i]);
		i++;
	}
}
