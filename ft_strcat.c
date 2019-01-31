/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:48:45 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:52:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[(len + i)] = s2[i];
		i++;
	}
	s1[(len + i)] = '\0';
	return (&s1[0]);
}
