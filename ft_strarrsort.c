/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/03/21 21:50:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrsort(char **arr)
{
	size_t	i;
	size_t	j;
	char	*current;

	i = 1;
	if (arr == NULL)
		return ;
	while (arr[i] != 0)
	{
		j = i;
		current = arr[i];
		while (j > 0 && ft_strcmp(arr[j - 1], current) > 0)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
