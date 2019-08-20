/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_strnindex(char **arr, char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_strequ(str, arr[i]))
			return (i);
		i++;
	}
	return (-1);
}
