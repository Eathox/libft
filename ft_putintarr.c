/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putintarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:18:27 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:50:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putintarr(const int *arr, int len)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		write(1, "\n", 1);
		i++;
	}
}
