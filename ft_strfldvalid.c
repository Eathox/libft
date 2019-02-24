/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfldvalid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 14:01:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfldvalid(const char **arr, int x, int y, const char *dlm)
{
	int		i;
	int		j;

	i = 0;
	if (arr == NULL || dlm == NULL)
		return (FALSE);
	if (ft_strarrnlen(arr, (size_t)y + 1) != (size_t)y)
		return (FALSE);
	while (i < y)
	{
		j = 0;
		if (ft_strnlen(arr[i], (size_t)x + 1) != (size_t)x)
			return (FALSE);
		while (j < x)
		{
			if (ft_chrin(dlm, arr[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}