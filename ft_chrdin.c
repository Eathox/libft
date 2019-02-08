/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/08 13:21:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrdin(const char *tab, char *c)
{
	unsigned int	i;

	i = 0;
	if (tab == NULL || c == NULL)
		return (FALSE);
	while (c[i] != '\0')
	{
		if (ft_chrin(tab, c[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
