/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 18:43:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**delarr(char **arr, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char			**ft_strarrnew(int x, int y, char c)
{
	char	**arr;
	int		i;

	if (x <= 0 || y <= 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (y + 1));
	if (arr == NULL)
		return (NULL);
	arr[y] = 0;
	i = 0;
	while (i < y)
	{
		arr[i] = ft_strnew(x);
		if (arr[i] == NULL)
			return (delarr(arr, i));
		ft_memset(arr[i], c, x);
		i++;
	}
	return (arr);
}
