/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolowerstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:20:29 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:12:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tolowerstr(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}
