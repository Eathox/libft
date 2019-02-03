/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chnrin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:39:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrnin(const char *tab, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (tab == NULL)
		return (FALSE);
	while (i < len)
	{
		if (tab[i] == n)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
