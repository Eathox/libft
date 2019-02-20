/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:53:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strin(const char **arr, const char *s)
{
	unsigned int	i;

	i = 0;
	if (arr == NULL || s == NULL)
		return (FALSE);
	while (arr[i] != NULL)
	{
		if (ft_strequ(s, arr[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
