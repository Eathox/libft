/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:16:43 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 19:03:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"


//FIX
char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t			i;
	size_t			str1len;
	size_t			str2len;
	char			*str;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	str = ft_strnew(str1len + str2len);
	if (str == NULL)
		return (NULL);
	while (i < (str1len + str2len))
	{
		if (i < str1len)
			str[i] = str1[i];
		else
			str[i] = str2[i - str1len];
		i++;
	}
	str[i] = '\0';
	return (str);
}
