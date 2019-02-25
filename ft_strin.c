/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:11:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strin(const char **arr, const char *str)
{
	size_t	i;

	i = 0;
	if (arr == NULL || str == NULL)
		return (FALSE);
	while (arr[i] != NULL)
	{
		if (ft_strequ(str, arr[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
