/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_arr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/23 15:59:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	totallen(const char **arr)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (arr[i] != NULL)
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len);
}

static char		*joinstrs(char *str, const char **arr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (arr[j] != NULL)
	{
		if (arr[j][k] == '\0')
		{
			k = 0;
			j++;
			continue;
		}
		str[i] = arr[j][k];
		i++;
		k++;
	}
	return (str);
}

char			*ft_strjoin_arr(const char **arr)
{
	char	*str;

	if (arr == NULL)
		return (NULL);
	str = ft_strnew(totallen(arr));
	if (str == NULL)
		return (NULL);
	str = joinstrs(str, arr);
	return (str);
}
