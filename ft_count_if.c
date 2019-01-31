/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_if.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:40:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, int (*f)(char*))
{
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (f == NULL || tab == NULL)
		return (0);
	while (tab[i] != NULL)
	{
		i++;
		if (f(tab[i]) == 1)
			count++;
	}
	return (count);
}
