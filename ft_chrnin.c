/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrnin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_chrnin(const char *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	while (i < n)
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
