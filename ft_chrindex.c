/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/02/03 22:38:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrindex(const char *tab, int c)
{
	unsigned int	i;

	i = 0;
	if (tab == NULL)
		return (-1);
	while (tab[i] != '\0')
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
