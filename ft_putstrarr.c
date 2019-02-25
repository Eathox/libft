/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:12:56 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:10:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(const char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != 0)
	{
		ft_putendl(arr[i]);
		i++;
	}
}
