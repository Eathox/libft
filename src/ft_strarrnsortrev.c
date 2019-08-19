/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrnsortrev.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:45:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	ft_strarrnsortrev(char **arr, t_bool (*f)(char *, char *), size_t n)
{
	size_t	i;
	size_t	j;
	char	*current;

	i = 1;
	while (i < n && arr[i] != NULL)
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
