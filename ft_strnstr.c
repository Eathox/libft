/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:35:18 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 20:33:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)s);
	while (i < len && s[i] != '\0' && needle[j] != '\0')
	{
		j -= (j > 0 && s[i - j] != needle[0]);
		j -= (j > 0 && s[i] != needle[j]);
		j += (s[i] == needle[j]);
		i++;
	}
	j += (s[i - 1] == needle[j]);
	if (needle[j] == '\0')
		return ((char *)&s[i - j]);
	return (NULL);
}
