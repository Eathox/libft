/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/01/23 13:59:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrin(const char *tab, int c)
{
	unsigned int	i;

	i = 0;
	if (tab == NULL)
		return (FALSE);
	while (tab[i] != '\0')
		if (c == tab[i++])
			return (TRUE);
	return (FALSE);
}
