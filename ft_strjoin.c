/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:16:43 by pholster       #+#    #+#                */
/*   Updated: 2019/01/20 17:25:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				s1len;
	int				s2len;
	char			*str;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = ft_strnew(s1len + s2len);
	if (str == NULL)
		return (NULL);
	while (++i < (s1len + s2len))
	{
		if (i < s1len)
			str[i] = s1[i];
		else
			str[i] = s2[i - s1len];
	}
	str[i] = '\0';
	return (str);
}
