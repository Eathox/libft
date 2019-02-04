/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:35:14 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 20:47:48 by pholster      ########   odam.nl         */
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
		if (j > 0 && haystack[i - j] != needle[0])
			j--;
		if (j > 0 && haystack[i] != needle[j])
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
