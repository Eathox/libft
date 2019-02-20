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

char	*ft_strrchr(const char *str, int c)
{
	int	l;
	int	i;

	i = 0;
	l = -1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			l = i;
		i++;
	}
	if (str[i] == c)
		l = i;
	if (l != -1)
		return ((char *)&str[l]);
	return (NULL);
}
