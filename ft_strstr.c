/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:35:14 by pholster       #+#    #+#                */
/*   Updated: 2019/01/20 14:57:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && needle[j] != '\0')
	{
		if (haystack[i - j] != needle[0] && j > 0)
			j--;
		if (haystack[i] != needle[j] && j > 0)
			j--;
		if (haystack[i] == needle[j])
			j++;
		i++;
	}
	if (haystack[i - 1] == needle[j])
		j++;
	if (needle[j] == '\0')
		return ((char *)&haystack[i - j]);
	return (NULL);
}
