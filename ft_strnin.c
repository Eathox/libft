/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:53:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnin(const char **arr, const char *str, size_t n)
{
	size_t	i;

	i = 0;
	if (arr == NULL || str == NULL)
		return (FALSE);
	while (i < n)
	{
		if (ft_strequ(str, arr[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
