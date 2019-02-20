/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:12:56 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:51:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(const char **arr)
{
	unsigned int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != 0)
	{
		ft_putendl(arr[i]);
		i++;
	}
}
