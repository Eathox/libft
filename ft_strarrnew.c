/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strarrnew(size_t size)
{
	size_t	i;
	char	**arr;

	i = 0;
	arr = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	while (i <= size)
	{
		arr[i] = NULL;
		i++;
	}
	return (arr);
}
