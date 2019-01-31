/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:26:07 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:55:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;
	int	i;

	i = 0;
	l = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			l = i;
		i++;
	}
	if (s[i] == c)
		l = i;
	if (l != -1)
		return ((char *)&s[l]);
	return (NULL);
}
