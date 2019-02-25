/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfldvalid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:27:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfldvalid(const char **arr, int x, int y, const char *dlm)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (arr == NULL || dlm == NULL || x <= 0 || y <= 0)
		return (FALSE);
	if (ft_strarrnlen(arr, (size_t)y + 1) != (size_t)y)
		return (FALSE);
	while (i < (size_t)y)
	{
		j = 0;
		if (ft_strnlen(arr[i], (size_t)x + 1) != (size_t)x)
			return (FALSE);
		while (j < (size_t)x)
		{
			if (ft_chrin(dlm, arr[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
