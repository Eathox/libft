/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupperstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:20:29 by pholster       #+#    #+#                */
/*   Updated: 2019/03/23 00:25:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupperstr(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
