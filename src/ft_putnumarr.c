/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnumarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:18:27 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_putnumarr(intmax_t *arr, size_t len)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (ft_putstr(NULL));
	while (i < len)
	{
		if (ft_putnum(arr[i]) == FALSE)
			return (FALSE);
		if (ft_putchar('\n') == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
