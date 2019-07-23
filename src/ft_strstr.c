/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:35:14 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:26:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

char	*ft_strstr(const char *str, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && needle[j] != '\0')
	{
		j -= (j > 0 && str[i - j] != needle[0]);
		j -= (j > 0 && str[i] != needle[j]);
		j += (str[i] == needle[j]);
		i++;
	}
	j += (str[i - 1] == needle[j]);
	if (needle[j] == '\0')
		return ((char *)&str[i - j]);
	return (NULL);
}
