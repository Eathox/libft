/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfieldvalid.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 09:29:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfieldvalid(const char **arr, int x, int y, const char *delims)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	if (ft_strarrlen(arr) != (size_t)y)
		return (FALSE);
	while (i < y)
	{
		j = 0;
		if (ft_strlen(arr[i]) != (size_t)x)
			return (FALSE);
		while (j < x)
		{
			if (ft_chrin(delims, arr[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
