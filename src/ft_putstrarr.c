/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:12:56 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 18:19:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_putstrarr(const char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (TRUE);
	while (arr[i] != 0)
	{
		if (ft_putendl(arr[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
