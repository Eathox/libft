/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/01/13 12:11:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	temp_a;
	unsigned char	temp_b;

	i = 0;
	while (i != -1)
	{
		temp_a = str1[i];
		temp_b = str2[i];
		if (temp_a != temp_b)
			return (temp_a - temp_b);
		if (temp_a == '\0')
			return (0);
		i++;
	}
	return (0);
}
