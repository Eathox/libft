/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:35:18 by pholster       #+#    #+#                */
/*   Updated: 2019/01/13 14:18:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		needlelen;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	needlelen = ft_strlen(needle);
	if (needlelen == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && j != needlelen && i < len)
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
	if (j == needlelen)
		return ((char *)&haystack[i - j]);
	return (NULL);
}
