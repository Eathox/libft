/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrsortrev.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:24:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

void	ft_strarrsortrev(char **arr, t_bool (*f)(char *, char *))
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
		while (j > 0 && f(current, arr[j - 1]) == FALSE)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}