/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:16:43 by pholster       #+#    #+#                */
/*   Updated: 2019/02/01 12:02:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int				i;
	int				s1len;
	int				s2len;
	char			*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = (int)ft_strlen(s1);
	s2len = (int)ft_strlen(s2);
	str = ft_strnew(s1len + s2len);
	if (str == NULL)
		return (NULL);
	while (i < (s1len + s2len))
	{
		if (i < s1len)
			str[i] = s1[i];
		else
			str[i] = s2[i - s1len];
		i++;
	}
	str[i] = '\0';
	return (str);
}
