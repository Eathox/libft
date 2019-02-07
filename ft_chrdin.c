/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/07 15:50:38 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrdin(const char *tab, char *c)
{
	unsigned int	i;

	i = 0;
	if (tab == NULL)
		return (FALSE);
	while (tab[i] != '\0')
	{
		if (ft_chrin(c, tab[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
