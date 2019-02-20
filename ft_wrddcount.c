/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wrddcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:26:33 by pholster       #+#    #+#                */
/*   Updated: 2019/01/16 13:52:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wrddcount(const char *str, const char *delims)
{
	unsigned int	count;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	count = 0;
	if (str == NULL || str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_chrin(delims, str[i]))
			j = 0;
		else if (j == 0)
		{
			count++;
			j = 1;
		}
		i++;
	}
	return (count);
}
