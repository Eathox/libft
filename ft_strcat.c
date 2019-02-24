/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:48:45 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 13:42:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str1);
	while (str2[i] != '\0')
	{
		str1[(len + i)] = str2[i];
		i++;
	}
	str1[(len + i)] = '\0';
	return (&str1[0]);
}
