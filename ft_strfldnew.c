/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfldnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_strfldnew(int x, int y, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (x <= 0 || y <= 0)
		return (NULL);
	arr = ft_strarrnew((size_t)y);
	if (arr == NULL)
		return (NULL);
	while (i < (size_t)y)
	{
		arr[i] = ft_strnew((size_t)x);
		if (arr[i] == NULL)
		{
			ft_strarrdel(&arr);
			return (NULL);
		}
		ft_memset(arr[i], c, x);
		i++;
	}
	return (arr);
}
