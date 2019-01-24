/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:26:00 by pholster       #+#    #+#                */
/*   Updated: 2019/01/15 20:24:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			return ((char *)&s[i]);
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
