/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/01/16 13:51:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intin(const int *tab, int n, int len)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (FALSE);
	while (i < len)
		if (tab[i++] == n)
			return (TRUE);
	return (FALSE);
}
